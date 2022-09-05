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

int	typeDetecter(std::string str)
{
	if (str == "-inff")
		return (N_INF_F);
	if (str == "+inff")
		return (P_INF_F);
	if (str == "nanf")
		return (NANF);
	if (str == "-inf")
		return (NEG_INF);
	if (str == "+inf")
		return (POS_INF);
	if (str == "nan")
		return (_NAN);

	unsigned	i;
	long	n = 0;
	bool	isNeg = false;
	for(i = 0; str[i] != 0; ++i) {
		if (str[i] == '-') {
			if (i == 0) {
				isNeg = true;
				continue ;
			}
			i = 0;
			break ;
		}
		if (!std::isdigit(str[i])) {
			i = 0;
			break;
		}
		n *= 10;
		n += str[i] - '0';
		if (isNeg) {
			if (n - 1 > std::numeric_limits<int>::max()) {
				i = 0;
				break;
			}
		} else {
			if (n > std::numeric_limits<int>::max()) {
				i = 0;
				break;
			}
		}
	}
	if (i == str.length()) {
		return INT;
	}

	char	*fraction;
	double d = std::strtod(str.c_str(), &fraction);
	if (str != fraction && d != HUGE_VAL) {
		if (str.at(str.length() - 1) == 'f') {
			if (d <= std::numeric_limits<float>::max() && d >= -std::numeric_limits<float>::max()) {
				return FLOAT;
			}
		} else {
			return DOUBLE;
		}
	}

	if (str.length() == 1 && str.at(0) >= 32 && str.at(0) <= 126) {
		return CHAR;
	}
	return UNKNOWN;
}
	
}
