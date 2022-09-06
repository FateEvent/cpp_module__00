#ifndef CONVERTER_H
# define CONVERTER_H

# include <iostream>
# include <string>
# include <cctype>
# include <cmath>
# include <cstdlib>
# include <limits>

enum type {
		UNKNOWN,
		CHAR,
		INT,
		FLOAT,
		N_INF_F,
		INF_F,
		NAN_F,
		DOUBLE,
		NEG_INF_D,
		INF_D,
		NAN_D
	};

class	Converter
{
private:
	
public:
	class Literals
	{
	private:
		char		_a;
		int			_i;
		float		_f;
		double	_d;

	public:
		Literals( void );
		~Literals ( void ) {};
		void	setLiteral( char a );
		void	setLiteral( int i );
		void	setLiteral( float f );
		void	setLiteral( double d );
	};

	Converter( std::string const& input );
	~Converter( void ) {};

	enum type	typeDetecter(std::string const& str);
};

#endif