#pragma once

#include <memory>

template<class T> class ContainerClass
{

public:
	class _iterator
	{
	public:
		_iterator(T* p)
			:_curr(p)
		{}

		_iterator& operator++()
		{
			++_curr;
			return *this;
		}

		_iterator& operator--()
		{
			--_curr;
			return *this;
		}

		T& operator*()
		{
			return *_curr;
		}

		bool operator==(const _iterator& b) const
		{
			return _curr == b._curr;
		}

		bool operator!=(const _iterator& b) const
		{
			return !(_curr == b._curr);
		}

	private:
		T* _curr;
	};

	ContainerClass();
	ContainerClass<T>& operator=(const ContainerClass<T>& arg);
	~ContainerClass();

	class _iterator;
	const _iterator cbegin() const;
	_iterator begin();
	const _iterator cend() const;
	_iterator end();

	void reserve(size_t newmalloc);
	void resize(size_t newsize, T val = T());
	size_t size() const;
	void push_back(const T& d);
	void remove(const T& d);

	T& operator[](int i);

	const T& operator[](int i) const;

private:
	size_t	_size;
	T* _elements;
	size_t	_space;
};

template<class T>
ContainerClass<T>::ContainerClass()
	:_size(0), _elements(0), _space(0)
{}

template<class T>
inline ContainerClass<T>& ContainerClass<T>::operator=(const ContainerClass<T>& a)
{
	if (this == &a) return *this;

	if (a._size <= _space)
	{
		for (int index = 0; index < a._size; ++index)
		{
			_elements[index] = a._elements[index];
			_size = a._size;
			return *this;
		}
	}

	T* p = new T[a._size];

	for (int index = 0; index < a._size; ++index)
		p[index] = a._elements[index];

	delete[] _elements;
	_size = a._size;
	_space = a._size;
	_elements = p;
	return *this;
}

template<class T>
ContainerClass<T>::~ContainerClass()
{
	delete[] _elements;
}

template<class T>
typename const ContainerClass<T>::_iterator ContainerClass<T>::cbegin() const
{
	return ContainerClass<T>::_iterator(&_elements[0]);
}

template<class T>
typename ContainerClass<T>::_iterator ContainerClass<T>::begin()
{
	return ContainerClass<T>::_iterator(&_elements[0]);
}

template<class T>
typename const ContainerClass<T>::_iterator ContainerClass<T>::cend() const
{
	return ContainerClass<T>::_iterator(&_elements[_size]);
}

template<class T>
typename ContainerClass<T>::_iterator ContainerClass<T>::end()
{
	return ContainerClass<T>::_iterator(&_elements[_size]);
}

template<class T>
inline void ContainerClass<T>::reserve(size_t newalloc)
{
	if (newalloc <= _space)
	{
		return;
	}

	T* p = new T[newalloc];

	for (int i = 0; i < _size; ++i)
	{
		p[i] = _elements[i];
	}

	delete[] _elements;
	_elements = p;
	_space = newalloc;
}

template<class T>
inline void ContainerClass<T>::resize(size_t newsize, T val)
{
	reserve(newsize);

	for (int index = _size; index < newsize; ++index)
	{
		_elements[index] = T();
	}

	_size = newsize;
}

template<class T>
inline size_t ContainerClass<T>::size() const
{
	return _size;
}

template<class T>
inline void ContainerClass<T>::push_back(const T& d)
{
	if (_space == 0)
	{
		reserve(8);
	}
	else if (_size == _space)
	{
		reserve(2 * _space);
	}

	_elements[_size] = d;
	++_size;
}

template<class T>
inline void ContainerClass<T>::remove(const T& d)
{
	for (int i = 0; i < _size; i++)
	{
		if (_elements[i] == d)
		{
			_elements[i].~T();
			for (int j = i; j < _size-1; j++)
			{
				_elements[j] = _elements[j+1];
			}
			
			--_size;
			return;
		}
	}
}

template<class T>
inline T& ContainerClass<T>::operator[](int i)
{
	return _elements[i];
}

template<class T>
inline const T& ContainerClass<T>::operator[](int i) const
{
	return _elements[i];
}
