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
			_freeIndices.push(i);
			_inUse[i] = false;
		}
	}

	~MemoryAllocator()
	{
		for (size_t i = 0; i < _pool.size(); ++i)
		{
			T* p = _pool[i];
			if (_inUse[i]) {
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
		size_t index;
		T* obj = nullptr;
		if (!_freeIndices.empty())
		{
			index = _freeIndices.top();
			_freeIndices.pop();
			obj = _pool[index];
		} 
		else
		{
			index = _pool.size();
			obj = reinterpret_cast<T*>(::operator new(sizeof(T)));
			_pool.push_back(obj);
			_inUse[index] = false;
		}

		new (obj) T(std::forward<Args>(args)...);
		obj->poolIndex = index;
		_inUse[index] = true;
		return obj;
	}

	void Deallocate(T* ptr)
	{
		if (!ptr) return;
		size_t index = ptr->poolIndex;

		if (ptr->poolIndex >= _pool.size() || _pool[ptr->poolIndex] != ptr) {
			std::cerr << "Invalid poolIndex or mismatched pointer: " << ptr << "\n";
			assert(false && "Corrupted poolIndex or invalid pointer");
			return;
		}

		if (index >= _pool.size() || _pool[index] != ptr)
		{
			std::cerr << "Error: Attempted to deallocate unmanaged pointer " << ptr << "\n";
			assert(false && "Invalid deallocation");
			return;
		}
		if (!_inUse[index])
		{
			std::cerr << "Error: Double deallocation detected for pointer " << ptr << "\n";
			assert(false && "Double free detected");
			return;
		}
		if constexpr (!std::is_trivially_destructible_v<T>)
		{
			ptr->~T();
		}
		_freeIndices.push(index);
		_inUse[index] = false;
	}

private:
	std::vector<T*> _pool;
	std::stack<size_t> _freeIndices;
	std::unordered_map<size_t, bool> _inUse;
};