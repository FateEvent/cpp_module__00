#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed( void );
	Fixed( Fixed const& other );
	~Fixed( void );
	Fixed&				operator = ( Fixed const & other ) throw ();
	int					getRawBits( void ) const;
	void				setRawBits( int const raw );
	Fixed( int const num );
	Fixed( float const num );
	int					toInt( void ) const;
	float				toFloat( void ) const;

private:
	int                 _value;
	static const int    _bits;
};

std::ostream&	operator << (std::ostream& os, const Fixed& num);

#endif
