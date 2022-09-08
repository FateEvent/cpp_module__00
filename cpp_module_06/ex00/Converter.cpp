#include "converter.hpp"

void	interpreter( std::string const& input )
{
	switch (typeDetecter(input)) {
		case UNKNOWN:
			std::cout << "Unknown input" << std::endl;
			break ;
		case CHAR:
			convert(input.at(0));
			break ;
		case INT:
			convert(atoi(input.c_str()));
			break ;
		case FLOAT:
			convert(static_cast<float>(std::strtod(input.c_str(), NULL)));
			break ;
		case DOUBLE:
			convert(std::strtod(input.c_str(), NULL));
			break;
		case NAN_F:
			convert(std::numeric_limits<float>::quiet_NaN());
			break;
		case INF_F:
			convert(std::numeric_limits<float>::infinity());
			break;
		case N_INF_F:
			convert(-std::numeric_limits<float>::infinity());
			break;
		case NAN_D:
			convert(std::numeric_limits<double>::quiet_NaN());
			break;
		case INF_D:
			convert(std::numeric_limits<double>::infinity());
			break;
		case NEG_INF_D:
			convert(-std::numeric_limits<double>::infinity());
			break;
	}
}

enum type	typeDetecter(std::string const& str)
{
	if (str == "-inff")
		return (N_INF_F);
	if (str == "+inff")
		return (INF_F);
	if (str == "nanf")
		return (NAN_F);
	if (str == "-inf")
		return (NEG_INF_D);
	if (str == "+inf")
		return (INF_D);
	if (str == "nan")
		return (NAN_D);

	unsigned	i;
	long	n = 0;
	bool	isNeg = false;
	for(i = 0; str[i] != 0; ++i) {
		if (str[i] == '-') {
			if (i == 0 && (str[i + 1] >= 48 && str[i + 1] <= 57)) {
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


void	convert( char a )
{
	std::cout << "char" << a << std::endl;
	std::cout << "char: " << a << std::endl;

	int	i = static_cast<int>(a);
	std::cout << "int: " << i << std::endl;

	float	f = static_cast<float>(a);
	std::cout << "float: " << f << ".0f" << std::endl;

	double	d = static_cast<double>(a);
	std::cout << "double: " << d << ".0" << std::endl;
}


void	convert( int i )
{
	std::cout << "int" << i << std::endl;
	if (i > std::numeric_limits<char>::max()) {
		std::cout << "char: Overflow" << std::endl;
	} else if (i < std::numeric_limits<char>::min()) {
		std::cout << "char: Underflow" << std::endl;
	} else if (i >= 32 && i <= 126) {
		char	a = static_cast<char>(i);
		std::cout << "char: " << a << std::endl;
	} else if (i < 32 || i > 126) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: Impossible" << std::endl;
	}

	std::cout << "int: " << i << std::endl;

	float	f = static_cast<float>(i);
	std::cout << "float: " << f << ".0f" << std::endl;

	double	d = static_cast<double>(i);
	std::cout << "double: " << d << ".0" << std::endl;
}

void	convert( float f )
{
	std::cout << "fl" << f << std::endl;
	if (f > std::numeric_limits<char>::max()) {
		std::cout << "char: Overflow" << std::endl;
	} else if (f < std::numeric_limits<char>::min()) {
		std::cout << "char: Underflow" << std::endl;
	} else if (f >= 32 && f <= 126) {
		char	a = static_cast<char>(f);
		std::cout << "char: " << a << std::endl;
	} else if (f < 32 || f > 126) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: Impossible" << std::endl;
	}

	if (f > std::numeric_limits<int>::max()) {
		std::cout << "int: Overflow" << std::endl;
	} else if (f < std::numeric_limits<int>::min()) {
		std::cout << "int: Underflow" << std::endl;
	} else if (f <= std::numeric_limits<int>::max() && f >= std::numeric_limits<int>::min()) {
		int	i = static_cast<int>(f);
		std::cout << "int: " << i << std::endl;
	} else {
		std::cout << "int: Impossible" << std::endl;
	}
	
	std::cout << "float: " << f << 'f' << std::endl;

	double	d = static_cast<double>(f);
	std::cout << "double: " << d << std::endl;
}

void	convert( double d )
{
	std::cout << "db" << d << std::endl;
	if (d > std::numeric_limits<char>::max()) {
		std::cout << "char: Overflow" << std::endl;
	} else if (d < std::numeric_limits<char>::min()) {
		std::cout << "char: Underflow" << std::endl;
	} else if (d >= 32 && d<= 126) {
		char	a = static_cast<char>(d);
		std::cout << "char: " << a << std::endl;
	} else if (d < 32 || d > 126) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: Impossible" << std::endl;
	}

	if (d > std::numeric_limits<int>::max()) {
		std::cout << "int: Overflow" << std::endl;
	} else if (d < std::numeric_limits<int>::min()) {
		std::cout << "int: Underflow" << std::endl;
	} else if (d <= std::numeric_limits<int>::max() && d >= std::numeric_limits<int>::min()) {
		int	i = static_cast<int>(d);
		std::cout << "int: " << i << std::endl;
	} else {
		std::cout << "int: Impossible" << std::endl;
	}
	
	if (d > std::numeric_limits<float>::max()) {
		std::cout << "float: Overflow" << std::endl;
	} else if (d < std::numeric_limits<float>::min()) {
		std::cout << "float: Underflow" << std::endl;
	} else {
		float	f = static_cast<float>(d);
		std::cout << "float: " << f << 'f' << std::endl;
	}

	std::cout << "double: " << d << std::endl;
}
