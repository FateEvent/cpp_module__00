#include "Converter.hpp"

int	main(int ac, char *av[])
{
	/*
	if (ac == 2)
	{
		std::string	input(av[1]);
		
		switch (typeDetecter(input)) {
			case CHAR:

		}
	}
	*/
	std::string	input(av[1]);
	Converter	converter(input.at(0));
}


