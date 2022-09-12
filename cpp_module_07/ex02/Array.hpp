#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include "ArrayException.hpp"

template <typename T = int>
class Array
{
public:
	Array( void ) : _size(0), _arr(new T[0])
	{
		std::cout << "The memory address of the newly created array is " << _arr << std::endl;
	}

	Array( unsigned int n ) : _size(n), _arr(new T[n])
	{
		for (std::size_t i = 0; i < _size; i++) {
			_arr[i] = i;
		}
		std::cout << "The memory address of the newly created array is " << _arr << std::endl;
	}

	Array( Array<T> const & src) : _size(src._size), _arr(new T[src._size])
	{
		for (std::size_t i = 0; i < _size; i++) {
			_arr[i] = src._arr[i];
		}
		std::cout << "The memory address of the newly created array is " << _arr << std::endl;
	}

	Array &	operator = ( Array const & src )
	{
		if (this == &src)
			return(*this);
		_size = src._size;
		delete[] _arr;
		_arr = new T[_size];
		for (std::size_t i = 0; i < _size; i++) {
			_arr[i] = src._arr[i];
		}
		std::cout << "The memory address of the newly created array is " << _arr << std::endl;
	}

	~Array( void )
	{
		delete[] _arr;
	}

	std::size_t	size( void ) const
	{
		return (_size);
	}

	T &	operator [] ( std::size_t const & index )
	{
		if (index >= _size )
			throw ArrayException("Array::InvalidIndexException");
		return (_arr[index]);
	}

	void	display( void )
	{
		for (std::size_t i = 0; i < _size; i++)
			std::cout << "array[" << i << "] = " << _arr[i] << std::endl;
	}

private:
	T*			_arr;
	std::size_t	_size;
};

template <typename T>
std::ostream&	operator << (std::ostream& os, Array<T>& arr)
{
	for (std::size_t i = 0; i < arr.size(); i++)
		os << "array[" << i << "] = " << arr[i] << std::endl;
	return (os);
}

#endif