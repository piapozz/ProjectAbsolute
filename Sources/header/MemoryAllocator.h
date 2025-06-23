#pragma once
#include <vector>
#include <stack>
#include <cassert>
#include <type_traits>
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
		}
	}

	~MemoryAllocator()
	{
		for (T* p : _pool)
		{
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
		}

		new (obj) T(std::forward<Args>(args)...);
		return obj;
	}

	void Deallocate(T* ptr)
	{
		if constexpr (!std::is_trivially_destructible_v<T>)
		{
			ptr->~T();
		}

		auto it = _ptrToIndex.find(ptr);
		if (it != _ptrToIndex.end())
		{
			_freeIndices.push(it->second);
		}
	}

private:
	std::vector<T*> _pool;
	std::stack<size_t> _freeIndices;
	std::unordered_map<T*, size_t> _ptrToIndex;
};