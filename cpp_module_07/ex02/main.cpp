#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}

	numbers.display();

	delete [] mirror;

	std::cout << std::endl << "My tests" << std::endl << std::endl;

	::Array<> empty;
	::Array<std::string>	tab(6);
	tab[0] = "mamma";
	tab[1] = "mia";
	tab[2] = "here";
	tab[3] = "we";
	tab[4] = "go";
	tab[5] = "again";

	::Array<>	arr(6);
	
	try
	{
		std::cout << tab[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << tab[-5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

//	std::cout << tab[9] << std::endl;
//	libc++abi.dylib: terminating with uncaught exception of type ArrayException: Array::InvalidIndexException
//	zsh:	abort			./array

	tab.display();
	std::cout << std::endl << arr << std::endl;

	return 0;
}