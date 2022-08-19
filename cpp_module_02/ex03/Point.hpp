#ifndef POINT_H
# define POINT_H

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point {
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point( void );
    Point( float const a, float const b );
    Point( Point const& cpy );
    Point&  operator = ( Point const & cpy ) throw ();
    ~Point( void );
    float   getX( void ) const;
    float   getY( void ) const;

    friend std::ostream&    operator << (std::ostream& os, const Point& val);
};

bool    bsp( Point const a, Point const b, Point const c, Point const point);

#endif
