#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include "ArrayException.hpp"

template <typename T = int>
class Array
{
public:
	Array( void ) : _size(0), _tab(new T[0])
	{
		std::cout << "tab = " << _tab << std::endl;
	}

	Array( unsigned int n ) : _size(n), _tab(new T[n])
	{
		for (size_t i = 0; i < _size; i++) {
			_tab[i] = 0;
			std::cout << "tab[" << i << "] = " << _tab[i] << std::endl;
		}
		std::cout << "tab = " << _tab << std::endl;
	}

	Array( Array<T> const & src) : _size(src._size), _tab(new T[src._size])
	{
		for (size_t i = 0; i < _size; i++) {
			_tab[i] = src._tab[i];
			std::cout << "tab[" << i << "] = " << _tab[i] << std::endl;
		}
		std::cout << "tab = " << _tab << std::endl;
	}

	Array &	operator = ( Array const & src )
	{
		if (this == &src)
			return(*this);
		_size = src._size;
		delete[] _tab;
		_tab = new T[_size];
		for (size_t i = 0; i < _size; i++) {
			_tab[i] = src._tab[i];
			std::cout << "tab[" << i << "] = " << _tab[i] << std::endl;
		}
		std::cout << "tab = " << _tab << std::endl;
	}

	~Array( void )
	{
		delete[] _tab;
	}

	size_t	size( void ) const
	{
		return (_size);
	}

	T &	operator [] ( size_t const & index )
	{
		std::cout << index << std::endl;
		if (index < 0 || index >= _size )
			throw ArrayException("Array::InvalidIndexException");
		return (_tab[index]);
	}

private:
	T*			_tab;
	size_t	_size;
};

#endif