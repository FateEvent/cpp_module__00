#include "Point.hpp"

static float	distance(Point const a, Point const b)
{
	return (sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) + (a.getY()  -  b.getY()) * (a.getY()  -  b.getY())));
}


bool	isBetween(Point const a, Point const b, Point const p)
{
	return (distance(a,p) + distance(p,b) == distance(a,b));
}