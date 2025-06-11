#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <functional>
#include <typeinfo>
#include <cassert>
#include "BaseObject.h"
#include "ObjectManager.h"
#include "MemoryAllocator.h"

class BaseAllocatorWrapper;
template<typename T>
class AllocatorWrapper;

// �I�u�W�F�N�g�̐����ƍ폜���Ǘ�����t�@�N�g���[�N���X
class ObjectFactory {
public:
	static ObjectFactory& Instance() {
		static ObjectFactory instance;
		return instance;
	}
	/// <summary>
	/// �I�u�W�F�N�g�̐����i�����Ȃ��j
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	T* Create();
	/// <summary>
	/// �I�u�W�F�N�g�̐����i��������j
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <typeparam name="...Args"></typeparam>
	/// <param name="...args"></param>
	/// <returns></returns>
	template<typename T, typename... Args>
	T* CreateWithArgs(Args&&... args);
	/// <summary>
	/// �I�u�W�F�N�g�̐����i��������A�I�u�W�F�N�g�}�l�[�W���[�̒ǉ��Ȃ��j
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <typeparam name="...Args"></typeparam>
	/// <param name="...args"></param>
	/// <returns></returns>
	template<typename T, typename... Args>
	T* CreateChildWithArgs(Args&&... args);
	/// <summary>
	/// �I�u�W�F�N�g�̍폜
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="obj"></param>
	template<typename T>
	void Destroy(T* obj);

private:
	/// <summary>
	/// �N���X�̓o�^
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="key"></param>
	template<typename T>
	void Register(const std::string& key = T::StaticTypeName());
	/// <summary>
	/// �N���X�̓o�^�i��������j
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <typeparam name="...Args"></typeparam>
	template<typename T, typename... Args>
	void RegisterWithArgs();

	std::unordered_map<std::string, std::function<BaseObject*()>> _creators;
	std::unordered_map<std::string, std::unique_ptr<BaseAllocatorWrapper>> _allocators;
};


template<typename T>
void ObjectFactory::Register(const std::string& key)
{
	if (_allocators.find(key) != _allocators.end()) return;
	_allocators[key] = std::make_unique<AllocatorWrapper<T>>();
	_creators[key] = [this, key]() -> BaseObject*
	{
		return static_cast<BaseObject*>(
			static_cast<AllocatorWrapper<T>*>(_allocators[key].get())->Allocate()
		);
	};
}

template<typename T, typename... Args>
void ObjectFactory::RegisterWithArgs()
{
	std::string key = T::StaticTypeName();
	if (_allocators.find(key) == _allocators.end())
		_allocators[key] = std::make_unique<AllocatorWrapper<T>>();
	
	_creators[key] = [this, key]() -> BaseObject*
    {
        auto allocatorWrapper = static_cast<AllocatorWrapper<T>*>(_allocators[key].get());
        return allocatorWrapper->Allocate();
    };
}

template<typename T, typename... Args>
T* ObjectFactory::CreateWithArgs(Args&&... args)
{
	const std::string key = T::StaticTypeName();
	if (_allocators.find(key) == _allocators.end())
		RegisterWithArgs<T, Args...>();
	
	auto allocatorWrapper = static_cast<AllocatorWrapper<T>*>(_allocators[key].get());
	T* obj = allocatorWrapper->Allocate(std::forward<Args>(args)...);
	ObjectManager::Instance().AddObject(obj);
	return obj;
}

template<typename T, typename... Args>
T* ObjectFactory::CreateChildWithArgs(Args&&... args)
{
	const std::string key = T::StaticTypeName();
	if (_allocators.find(key) == _allocators.end())
		RegisterWithArgs<T, Args...>();

	auto allocatorWrapper = static_cast<AllocatorWrapper<T>*>(_allocators[key].get());
	T* obj = allocatorWrapper->Allocate(std::forward<Args>(args)...);
	return obj;
}

template<typename T>
T* ObjectFactory::Create()
{
	Register<T>();
	std::string key = T::StaticTypeName();
	auto itCreator = _creators.find(key);
	return static_cast<T*>(itCreator->second());
}

template<typename T>
void ObjectFactory::Destroy(T* obj)
{
	if (!obj) return;

	ObjectManager::Instance().RemoveObject(obj);
	const std::string key = T::StaticTypeName();
	auto it = _allocators.find(key);
	if (it != _allocators.end())	
		it->second->DeallocateBase(obj);
	else	
		delete obj;
}

class BaseAllocatorWrapper {
public:
	virtual ~BaseAllocatorWrapper() = default;

	virtual BaseObject* AllocateBase() = 0;
	virtual void DeallocateBase(BaseObject* obj) = 0;
};

template<typename T>
class AllocatorWrapper: public BaseAllocatorWrapper {
public:
	AllocatorWrapper(): allocator() {
	}

	template<typename... Args>
	T* Allocate(Args&&... args) {
		return allocator.Allocate(std::forward<Args>(args)...);
	}

	virtual BaseObject* AllocateBase() override {
		return allocator.Allocate();
	}

	virtual void DeallocateBase(BaseObject* obj) override {
		allocator.Deallocate(static_cast<T*>(obj)); 
	}

private:
	MemoryAllocator<T> allocator;
};