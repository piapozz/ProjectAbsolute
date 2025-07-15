#pragma once
#include <vector>
#include <stack>
#include <cassert>
#include <type_traits>
#include <unordered_map>
#include <iostream>

template<typename T>
class MemoryAllocator
{
public:
	MemoryAllocator(size_t capacity = 1000)
	{
		_pool.reserve(capacity);
		for (size_t i = 0; i < capacity; ++i)
		{
			T* obj = reinterpret_cast<T*>(::operator new(sizeof(T)));
			_pool.push_back(obj);
			_ptrToIndex[obj] = i;
			_freeIndices.push(i);
			_inUse[obj] = false;
		}
	}

	~MemoryAllocator()
	{
		for (T* p : _pool)
		{
			if (_inUse[p]) {
				std::cerr << "Warning: Leaked object detected at " << p << "\n";
				if constexpr (!std::is_trivially_destructible_v<T>)
				{
					p->~T();
				}
			}
			::operator delete(p);
		}
	}

	template<typename... Args>
	T* Allocate(Args&&... args)
	{
		T* obj = nullptr;
		if (!_freeIndices.empty())
		{
			size_t index = _freeIndices.top();
			_freeIndices.pop();
			obj = _pool[index];
		} else
		{
			obj = reinterpret_cast<T*>(::operator new(sizeof(T)));
			_ptrToIndex[obj] = _pool.size();
			_pool.push_back(obj);
			_inUse[obj] = false;
		}

		new (obj) T(std::forward<Args>(args)...);
		_inUse[obj] = true;
		return obj;
	}

	void Deallocate(T* ptr)
	{
		auto it = _ptrToIndex.find(ptr);
		if (it == _ptrToIndex.end())
		{
			std::cerr << "Error: Attempted to deallocate unmanaged pointer " << ptr << "\n";
			assert(false && "Invalid pointer passed to Deallocate");
			return;
		}

		if (!_inUse[ptr])
		{
			std::cerr << "Error: Double deallocation detected for pointer " << ptr << "\n";
			assert(false && "Double free detected");
			return;
		}

		if constexpr (!std::is_trivially_destructible_v<T>)
		{
			ptr->~T();
		}

		_freeIndices.push(it->second);
		_inUse[ptr] = false;
	}

private:
	std::vector<T*> _pool;
	std::stack<size_t> _freeIndices;
	std::unordered_map<T*, size_t> _ptrToIndex;
	std::unordered_map<T*, bool> _inUse; // 使用中チェック
};
