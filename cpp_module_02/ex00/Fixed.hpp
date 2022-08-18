#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {
public:
    Fixed( void );
    Fixed( Fixed const& other );
    ~Fixed( void );
    Fixed & operator = ( Fixed const & other ) throw ();
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );

private:
    int                 _value;
    static const int    _bits;
};

#endif
