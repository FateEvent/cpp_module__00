#include <iostream>
#include "Harl.hpp"

int main(int ac, char *av[])
{
	Harl	harl;

	if (ac == 1 || ac > 2)
	{
		std::cerr << "Invalid number of arguments!" << std::endl;
		return (1);
	}
	harl.complain( av[1] );
	return (0);
}
