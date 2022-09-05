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
	char		_a;
	int			_i;
	float		_f;
	double	_d;

public:
	Converter( char a );
	Converter( int i );
	~Converter( void ) {};
};

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

int	typeDetecter(std::string str);

#endif