#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	larry("Larry", 5);
	Bureaucrat	jean("Jean", 56);
	Bureaucrat	dwan("Dwan", 1);
	Bureaucrat	crazy("Crazy Boss", 0);
	Bureaucrat	jeremy("Jerry", 167);

	std::cout << larry << std::endl;
	std::cout << dwan << std::endl;
	std::cout << crazy << std::endl;

	crazy.demote();
	dwan.promote();

	std::cout << crazy << std::endl;
	std::cout << dwan << std::endl;
}
