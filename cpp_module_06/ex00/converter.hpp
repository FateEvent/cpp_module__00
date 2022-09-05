#ifndef CONVERTER_H
# define CONVERTER_H

# include <iostream>
# include <string>
# include <cctype>
# include <cmath>
# include <cstdlib>
# include <limits>

class	Converter
{
private:
	enum type {
		UNKNOWN,
		CHAR,
		INT,
		FLOAT,
		N_INF_F,
		P_INF_F,
		NANF,
		DOUBLE,
		NEG_INF,
		POS_INF,
		_NAN
	};

public:
	class Literals
	{
	private:
		char		_a;
		int			_i;
		float		_f;
		double	_d;

	public:
		Literals( char a );
		Literals( int i );
		~Literals ( void ) {};
	};

	Converter( std::string const& input );
	~Converter( void ) {};


	enum type	typeDetecter(std::string const& str);
};

#endif