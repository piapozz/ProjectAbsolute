#pragma once
#include <vector>
#include <stack>
#include <cassert>

template<typename T>
class MemoryAllocator
{
public:
	MemoryAllocator(size_t capacity = 100) 
	{
		_pool.reserve(capacity);
		for (size_t i = 0; i < capacity; ++i)
		{
			_freeIndices.push(i);
			_pool.push_back(new T());
		}
	}

	~MemoryAllocator() 
	{
		for (T* p : _pool)
		{
			delete p;
		}
		_pool.clear();
	}

	template<typename... Args>
	T* Allocate(Args&&... args)
	{
		if (_freeIndices.empty())
		{
			T* p = new T(std::forward<Args>(args)...);
			_pool.push_back(p);
			return p;
		}
		size_t index = _freeIndices.top();
		_freeIndices.pop();
		T* p = _pool[index];
		p = new T(std::forward<Args>(args)...);
		
		return p;
	}

	void Deallocate(T* ptr) 
	{
		auto it = std::find(_pool.begin(), _pool.end(), ptr);
		assert(it != _pool.end() && "Invalid pointer deallocation");
		size_t index = std::distance(_pool.begin(), it);
		_freeIndices.push(index);
	}

private:
	std::vector<T*> _pool;
	std::stack<size_t> _freeIndices;
};
