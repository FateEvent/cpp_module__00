# include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed( void ) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed( Fixed const& other ) : _value(other._value)
{
    std::cout << "Copy constructor called" << std::endl;
}


Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}


Fixed & Fixed::operator = (Fixed const & other) throw ()
{
    if (this == & other)
        return  (*this);
    this->_value = other._value;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);

}


int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}


void    Fixed::setRawBits( int const raw )
{
    std::cout << "SetRawBits member function called" << std::endl;
    this->_value = raw;
}
