#include <iostream>
#include <string>
#include <locale>

int main(int ac, char *av[])
{
	int	index;

	index = 1;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (ac > 1)
	{
		while (av[index])
		{
			std::locale	loc;
			std::string	str = av[index];
			for (std::string::size_type i = 0; i < str.length(); ++i)
				std::cout << std::toupper(str[i], loc);
			if (index < ac - 1)
				std::cout << ' ';
			++index;
		}
	}
	return 0;
}
