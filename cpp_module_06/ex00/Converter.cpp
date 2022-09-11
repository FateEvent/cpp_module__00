#include "converter.hpp"

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
		return (INT);
	}

	char	*fraction;
	double d = std::strtod(str.c_str(), &fraction);
	if (str != fraction && d != HUGE_VAL) {
		if (str.at(str.length() - 1) == 'f') {
			if (d <= std::numeric_limits<float>::max() && d >= -std::numeric_limits<float>::max())
				return (numericValuesHandler(str));
		} else if (d <= std::numeric_limits<double>::max() && d >= -std::numeric_limits<double>::max())
			return (numericValuesHandler(str));
	}

	if (str.length() == 1 && str.at(0) >= 32 && str.at(0) <= 126) {
		return (CHAR);
	}
	return (UNKNOWN);
}

void	convert( char a )
{
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
	if (i > std::numeric_limits<char>::max()) {
		std::cout << "char: Overflow" << std::endl;
	} else if (i < std::numeric_limits<char>::min()) {
		std::cout << "char: Underflow" << std::endl;
	} else if (i >= 32 && i <= 126) {
		char	a = static_cast<char>(i);
		std::cout << "char: " << a << std::endl;
	} else if ((i >= 0 && i < 32) || i == 127) {
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
	if (f > std::numeric_limits<char>::max()) {
		std::cout << "char: Overflow" << std::endl;
	} else if (f < std::numeric_limits<char>::min()) {
		std::cout << "char: Underflow" << std::endl;
	} else if (f >= 32 && f <= 126) {
		char	a = static_cast<char>(f);
		std::cout << "char: " << a << std::endl;
	} else if ((f >= 0 && f < 32) || f == 127) {
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
	
	std::cout << "float: " << f << printDotZero(static_cast<double>(f)) << 'f' << std::endl;

	double	d = static_cast<double>(f);
	std::cout << "double: " << d << printDotZero(static_cast<double>(f)) << std::endl;
}

void	convert( double d )
{
	if (d > std::numeric_limits<char>::max()) {
		std::cout << "char: Overflow" << std::endl;
	} else if (d < std::numeric_limits<char>::min()) {
		std::cout << "char: Underflow" << std::endl;
	} else if (d >= 32 && d <= 126) {
		char	a = static_cast<char>(d);
		std::cout << "char: " << a << std::endl;
	} else if ((d >= 0 && d < 32) || d == 127) {
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
	} else if (d < -std::numeric_limits<float>::max()) {
		std::cout << "float: Underflow" << std::endl;
	} else {
		float	f = static_cast<float>(d);
		std::cout << "float: " << f << printDotZero(d) << 'f' << std::endl;
	}

	std::cout << "double: " << d << printDotZero(d) << std::endl;
}
