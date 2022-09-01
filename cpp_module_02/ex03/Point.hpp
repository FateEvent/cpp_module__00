#ifndef POINT_H
# define POINT_H

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point {
private:
	Fixed const	_x;
	Fixed const	_y;

	Point&	operator = ( Point const & cpy ) throw ();

public:
	Point( void );
	Point( float const a, float const b );
	Point( Point const& cpy );
	~Point( void );
	float	getX( void ) const;
	float	getY( void ) const;

	Point	operator+(Point point) const;
	Point	operator-(Point point) const;

};

std::ostream&	operator << (std::ostream& os, const Point& value);
bool			bsp( Point const a, Point const b, Point const c, Point const point);
bool			isBetween(Point const a, Point const b, Point const p);

#endif
