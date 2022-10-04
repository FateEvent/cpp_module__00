#include <iostream>
#include "Span.hpp"

int main()
{
	Span	span(10);
	
	span.addNumber(10);
	span.addNumber(12);
	span.addNumber(15);
	span.addNumber(34);
	span.addNumber(18);

	for (int i = 0; i < span.getSize(); i++)
		std::cout << span[i] << std::endl;
	std::cout << std::endl;

	std::cout << "The spans are as follows:" << std::endl;
	std::cout << "The longest span is: " << span.longestSpan() << std::endl;
	std::cout << "The shortest span is: " << span.shortestSpan() << std::endl;

	try {
		std::cout << span[6] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	Span	sp2(10000);

	sp2.addManyANumber();

	try {
		std::cout << sp2[1467] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	span.addManyANumber();

	std::cout << span[4] << std::endl;

	Span	empty(0);

	try {
		std::cout << "The shortest span is: " << empty.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	for (int i = 234; i < 245; i++)
		std::cout << sp2[i] << std::endl;

	return 0;
}
