#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	s1 = c.getY() - a.getY();
	float	s2 = c.getX() - a.getX();
	float	s3 = b.getY() - a.getY();
	float	s4 = point.getY() - a.getY();

	float	w1 = (a.getX() * s1 + s4 * s2 - point.getX() * s1) / (s3 * s2 - (b.getX()-a.getX()) * s1);
	float	w2 = (s4 - w1 * s3) / s1;

	bool	onIt = (isBetween(a, b, point) || isBetween(b, c, point) || isBetween(c, a, point));

	if (onIt)
	{
		std::cout << "The point " << point << " lies on the perimeter of the triangle made up of " << std::endl;
		std::cout << "a: " << a << ", b: " << b << ", c: " << c << "." << std::endl;
		return (!onIt);
	}

	std::cout << "Is the point " << point << " contained in the triangle composed of the points " << std::endl;
	std::cout << "a: " << a << ", b: " << b << ", c: " << c << " ? " << (w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1) << std::endl;
	
	return (w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1);
}
