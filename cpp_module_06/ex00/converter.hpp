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

Literals( void );
~Literals ( void ) {};
void	setLiteral( char a );
void	setLiteral( int i );
void	setLiteral( float f );
void	setLiteral( double d );

void	converter( std::string const& input );

enum type	typeDetecter(std::string const& str);

#endif