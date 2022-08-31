#include <iostream>
#include "Point.hpp"

int main( void ) {

	Point	a;
	Point	b( 10.5, 5 );
	Point	c( 8.5, 4 );
	Point	point( 0.5, 2 );

	Point	d( 5, 5 );
	Point	e( 2, 2 );
	Point	f( 7, 2 );
	Point	pt2( 5, 4 );

	Point	g;
	Point	h( 8.5, 0 );
	Point	i( 4.5, 7 );
	Point	pt3( 4, 3 );

	Point	l;
	Point	m( 8.5, 0 );
	Point	n( 4.5, 7 );
	Point	pt4( l );

	bsp( a, b, c, point);
	bsp( d, e, f, pt2);
	bsp( g, h, i, pt3);
	bsp( l, m, n, pt4);

	return (0);
}
