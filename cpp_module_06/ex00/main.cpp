#include <iostream>
#include <string>
#include <cstdlib>

int	main()
{
	std::cout << strtof("nanf", NULL) << std::endl;
	std::cout << strtof("4.0f", NULL) << std::endl;
	std::cout << strtof("0.42", NULL) << std::endl;
}