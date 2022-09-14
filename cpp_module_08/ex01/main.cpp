#include <iostream>
#include "Span.hpp"

int main()
{
	Span	span(5);
	
	span.addNumber(10);
	span.addNumber(12);
	span.addNumber(15);
	span.addNumber(34);
	span.addNumber(18);
	span.addNumber(15);

	std::cout << span.longestSpan() << std::endl;
	std::cout << span.shortestSpan() << std::endl;

	try {
		std::cout << span[6] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
