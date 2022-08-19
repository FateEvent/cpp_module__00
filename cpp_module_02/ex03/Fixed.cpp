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


Fixed&  Fixed::operator = (Fixed const & other) throw ()
{
    if (this == & other)
        return (*this);
    this->_value = other._value;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
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


// The number is multiplied (<<) by the number of bits stored (8)
// so that it creates more space for storing the numbers behind
// the point

Fixed::Fixed( int const num )
{
    std::cout << "Int constructor called" << std::endl;
    _value = roundf(num << this->_bits);
}


Fixed::Fixed( float const num )
{
    std::cout << "Float constructor called" << std::endl;
    _value = (num * (float)(1 << this->_bits));
}


// The number is divided (>>) by the number of bits stored (8)
// so that the stored number is transformed again into the
// original one

int Fixed::toInt( void ) const
{
    return (this->_value >> this->_bits);
}


float   Fixed::toFloat( void ) const
{
    return ((float)this->_value / (float)(1 << this->_bits));
}


std::ostream&    operator << (std::ostream& os, const Fixed& num)
{
    os << num.toFloat();
    return os;
}


// Overloaded Comparison Operators
bool    Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}


bool	Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}


bool	Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}


bool	Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}


bool	Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}


bool	Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}


// Overloaded Arithmetic Operators
float	Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}


float	Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}


float	Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}


float	Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}


// Overloaded pre-increment Operators
Fixed	Fixed::operator++()
{
	this->_value++;
	return (*this);
}


Fixed	Fixed::operator--()
{
	this->_value--;
	return (*this);
}


// Overloaded post-increment Operators
Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->_value;
	return (tmp);
}


Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->_value;
	return (tmp);
}


Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}


const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}


Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}


const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}
