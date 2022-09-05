#include "Converter.hpp"

Converter::Converter( std::string const& input )
{
	switch (typeDetecter(input)) {
			case CHAR:
				Literals	literals(input.at(0));
			case default:
				;
		}

	
}

enum type	Converter::typeDetecter(std::string const& str)
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


Converter::Literals::Literals( char a ) : _a(a), _i(static_cast<int>(a)),
	_f(static_cast<float>(a)), _d(static_cast<double>(a))
{
	std::cout << "char: " << _a << std::endl;

	std::cout << "int: " << _i << std::endl;
	
	std::cout << "float: " << _f << 'f' << std::endl;

	std::cout << "double: " << _d << std::endl;
}


Converter::Literals::Literals( int i ) : _i(i), _f(static_cast<float>(i)), _d(static_cast<double>(i))
{
	if (i >= 32 && i <= 126) {
		char c = static_cast<char>(i);
		std::cout << "char: " << c << std::endl;
	} else if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min()) {
		std::cout << "char: Overflow" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}

	std::cout << "int: " << _i << std::endl;

	std::cout << "float: " << _f << 'f' << std::endl;

	std::cout << "double: " << _d << std::endl;
}