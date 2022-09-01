#include "Point.hpp"

static double	squareRoot(double num)
{
	double	lower_bound = 0; 
	double	upper_bound = num;
	double	temp = 0;
	int		nCount = 50;
	while(nCount != 0)
	{
		temp=(lower_bound + upper_bound) / 2;
		if(temp * temp == num) 
		{
			return temp;
		}
		else if(temp * temp > num)
		{
			upper_bound = temp;
		}
		else
			lower_bound = temp;
		nCount--;
	}
	return temp;
}

static float	distance(Point const a, Point const b)
{
	return (squareRoot((a.getX() - b.getX()) * (a.getX() - b.getX()) + (a.getY()  -  b.getY()) * (a.getY()  -  b.getY())));
}


bool	isBetween(Point const a, Point const b, Point const p)
{
	return (distance(a,p) + distance(p,b) == distance(a,b));
}