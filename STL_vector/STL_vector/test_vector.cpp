#include<iostream>
using namespace std;

namespace bit
{
template<class T>
class vector
{
public:
	typedef T* iterator;
	typedef const* const_iterator;
public:
	iterator begin() { return _start; }
	iterator end() { return _finish; }

	const_iterator cbegin() { return _start; }
	const_iterator cend() { return _finish; }
public:
	vector()
		:_start(nullptr)
		 ,_finish(nullptr)
		 ,endOfStorage(nullptr)
	{}
	vector(int n, const T& value = T())
		:_start(nullptr)
		, _finish(nullptr)
		, endOfStorage(nullptr)
	{
		reserve(n);
		while (n--)
		{
			push_back(value);
		}
	}
	template<class InputIterator>
	vector(InputIterator first, InputIterator last)
	{
		reserve(last - first);
		while (first != last)
		{
			push_back(*first);
			++first;
		}
	}

	vector(const vector<T>& v):_start(nullptr),_finish(nullptr),_endOfStorage(nullptr)
	{
		reserve(v.capacity());
		iterator it = begin();
		const_iterator vit = v.cbegin();
		while (vit != v.cend)
		{
			*it++ = *vit++;
		}
		_finish = _start + v.size();
		_endOfStorage = _start + v.capacity();
	}

	~vector()
	{
		delete[] _start;
		_start = _finish = _endOfStorage = nullptr;
	}

public:
	size_t size() const
	{
		return (_finish - _start);
	}
	size_t capacity() const
	{
		return (_endOfStorage - _start);
	}
public:
	T& operator[](size_t index)
	{
		assert(i < size());
		return _start[i];
	}
	void push_back(const T &value)
	{
		insert(end(), value);
	}
	void pop_back()
	{
		erase(--end());
	}
	void swap(vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endOfStorage, v._endOfStorage);
	}
public:
	iterator insert(iterator pos, const T& x)
	{
		if (size() == capacity())
		{
			int new_capacity = capacity() == 0 ? 1 : capacity() * 2;
			reserve(new_capacity);
		}
		iterator p = _finish;
		if (pos == nullptr)
			*_finish = x;
		else
		{
			while (p != pos)
			{
				*p = *(p - 1);
				p--;
			}
			*pos = x;
		}
		_finish++;
		return pos;
	}

	iterator erase(iterator pos)
	{
		iterator begin = pos + 1;
		while (begin != _finish)
		{
			*(begin - 1) = *begin;
			++begin;
		}
		--finish;
		return pos;
	}

	void resize(size_t n, const T &value = T())
	{
		if (n < size())
		{
			_finish = _start + n;
			return;
		}
		if (n > capacity())
		{
			reserve(n);
		}
		iterator p = _finish;
		_finish = _finish + n - size();
		while (p != _finish)
		{
			*p = value;
			++p;
		}
	}
	void reserve(size_t n)
	{
		if (n > capacity())
		{
			T *tmp = new T[n];
			int old_size = size();
			for (int i = 0; i < old_size; ++i)
			{
				tmp[i] = _start[i];
			}
			delete[] _start;
			_start = tem;
			_finish = _start + old_size;
			_endOfStorage = _start + n;
		}
	}


private:
	iterator _start;  //指向数据块的开始
	iterator _finish;    //指向有效数据的结尾
	iterator _endOfStorage;  //指向存储容量的尾
};
}