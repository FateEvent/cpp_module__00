#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{

}


Point::Point( float const a, float const b ) : _x(a), _y(b)
{

}


Point::Point( Point const& cpy ) : _x(cpy._x), _y(cpy._y)
{

}


Point&	Point::operator = ( Point const & cpy ) throw ()
{
	std::cout << "Point copy assignment operator called." << std::endl;
	std::cout << "It's impossible to assign a constant " << std::endl;
	std::cout << "member after having been initialised" << std::endl;
	return (*this);
}


Point::~Point( void )
{

}


float	Point::getX( void ) const
{
	return (this->_x.toFloat());
}


float	Point::getY( void ) const
{
	return (this->_y.toFloat());
}


std::ostream&	operator << (std::ostream& os, const Point& value)
{
	os << "[" << value.getX() << ", " << value.getY() << "]";
	return os;
}


// Overloaded Arithmetic Operators
Point	Point::operator+(Point point) const
{
	Point	result(this->getX() + point.getX(), this->getX() + point.getY());
	
	return (result);
}


Point	Point::operator-(Point point) const
{
	Point	result(this->getX() - point.getX(), this->getX() - point.getY());
	
	return (result);
}
