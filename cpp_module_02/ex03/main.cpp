#include <iostream>
#include "Point.hpp"

int main( void ) {

    Point   a;
    Point   b( 10.5, 5 );
    Point   c( 8.5, 4 );
    Point   point( 0.5, 2 );

    Point   d( 5, 5 );
    Point   e( 2, 2 );
    Point   f( 7, 2 );
    Point   pt2( 5, 4 );

    bsp( a, b, c, point);
    bsp( d, e, f, pt2);

    return (0);
}
