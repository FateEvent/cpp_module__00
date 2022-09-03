#include <iostream>

void    ft_str_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] -= 32;
			std::cout << str[i];
		}
		else
			std::cout << str[i];
		i++;
	}
}

int main(int ac, char *av[])
{
	int	i;

	if (ac == 1 || ac > 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (ac == 2)
	{
		i = 1;
		while (av[i]) {
			ft_str_capitalizer(av[i]);
			i++;
		}
		std::cout << std::endl;
	}
	return 0;
}
