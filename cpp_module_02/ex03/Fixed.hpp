#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
public:
    Fixed( void );
    Fixed( Fixed const& other );
    ~Fixed( void );
    Fixed&  operator = ( Fixed const & other ) throw ();
    int                     getRawBits( void ) const;
    void                    setRawBits( int const raw );

    Fixed( int const num );
    Fixed( float const num );
    int                     toInt( void ) const;
    float                   toFloat( void ) const;
    friend std::ostream&    operator << (std::ostream& os, const Fixed& num);

    // Comparison Operators
    bool                    operator>(Fixed fixed)const;
    bool                    operator<(Fixed fixed)const;
    bool                    operator>=(Fixed fixed)const;
    bool                    operator<=(Fixed fixed)const;
    bool                    operator==(Fixed fixed)const;
    bool                    operator!=(Fixed fixed)const;

    // Arithmetic Operators
    float                   operator+(Fixed fixed)const;
    float                   operator-(Fixed fixed)const;
    float                   operator*(Fixed fixed)const;
    float                   operator/(Fixed fixed)const;

    // pre-increment Operators
    Fixed                   operator++();
    Fixed                   operator--();
    // post-increment Operators
    Fixed                   operator++(int);
    Fixed                   operator--(int);

    static Fixed            &min(Fixed &first, Fixed &second);
    static const Fixed      &min(Fixed const &first, Fixed const &second);
    static Fixed            &max(Fixed &first, Fixed &second);
    static const Fixed      &max(Fixed const &first, const Fixed &second);

private:
    int                     _value;
    static const int        _bits;
};

#endif
