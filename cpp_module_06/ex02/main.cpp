#include <iostream>
#include "detect.hpp"

int	main()
{
	Base	*base;

	std::cout << "--------" << std::endl;
	std::cout << "Pointers" << std::endl;
	std::cout << "--------" << std::endl;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	std::cout << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << "References" << std::endl;
	std::cout << "----------" << std::endl;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;
}

