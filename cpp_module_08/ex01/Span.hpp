#ifndef SPAN_H
# define SPAN_H

# include <cstdlib>
# include <vector>
# include <algorithm>
# include <ctime>
# include "ArrayException.hpp"

class Span
{
private:
	std::vector<int>	_arr;
	unsigned 					_capacity;
	unsigned					_current;

public:
	Span( void );
	Span( unsigned capacity );
	Span( const Span& src );
	Span&	operator=( const Span& rhs );
	~Span( void );

	void addNumber( unsigned data );
	int&	getValue( unsigned const & index );
	int&	operator[]( unsigned const & index );

	std::size_t	getSize( void );
	unsigned getCapacity( void );
	void print( void );

	unsigned int	shortestSpan( void );
	unsigned int	longestSpan( void );
	void	addManyANumber( void );
};

#endif