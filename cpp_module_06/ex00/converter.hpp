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

void	convert( char a );
void	convert( int i );
void	convert( float f );
void	convert( double d );

void	interpreter( std::string const& input );

enum type	numericValuesHandler(std::string const& input);
enum type	typeDetecter(std::string const& str);
const char	*printDotZero(double number);

#endif