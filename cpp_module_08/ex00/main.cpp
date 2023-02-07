#include "easyfind.hpp"

/*
** About the use of the throw() function:
**  
** " Since throw will make the execution of the method stop immediately and control is passed back to the caller,
** it doesn't matter what your method returns. No matter what type you return, that type will not be returned,
** because you are throwing an exception (which indicates something wrong happened) on the first line."
** 
** <https://stackoverflow.com/questions/49066109/functions-return-type-can-be-exception-when-it-throws-exception>
*/

struct c_unique {
	int current;
	c_unique() {current = 0;}
	int operator()() {return ++current;}
}				UniqueNumber;

int	RandomNumber () { return (std::rand() % 100); }

int	main() {
	std::vector<int>	vec(100);

	vec.push_back(10);

	std::cout << "Generating random numbers to fill the vector" << std:: endl;
	std::srand (unsigned(std::time(0)));
	std::generate (vec.begin(), vec.end(), RandomNumber);

	std::cout << "Does our vector vec contain a 10? " << std::endl;

	try {
		if (easyfind(vec, 10) || easyfind(vec, 10) == 0) {
			std::cout << "It may be found at index:" << std::endl;
			std::cout << easyfind(vec, 10) << std::endl;
		}
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		std::cout << "Nope." << std::endl;
	}

	std::cout << "Does our vector vec contain a 98? " << std::endl;

	try {
		if (easyfind(vec, 98) || easyfind(vec, 98) == 0) {
			std::cout << "It may be found at index:" << std::endl;
			std::cout << easyfind(vec, 98) << std::endl;
		}
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		std::cout << "Nope." << std::endl;
	}

	std::cout << "Does our vector vec contain a 74? " << std::endl;

	try {
		if (easyfind(vec, 74) || easyfind(vec, 74) == 0) {
			std::cout << "It may be found at index:" << std::endl;
			std::cout << easyfind(vec, 74) << std::endl;
		}
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		std::cout << "Nope." << std::endl;
	}
}
