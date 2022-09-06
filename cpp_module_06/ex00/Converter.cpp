#include "Converter.hpp"

void	converter( std::string const& input )
{
	switch (typeDetecter(input)) {
		case UNKNOWN:
			std::cout << "Unknown input" << std::endl;
			break ;
		case CHAR:
			literals.setLiteral(input.at(0));
			break ;
		case INT:
			literals.setLiteral(atoi(input.c_str()));
			break ;
		case FLOAT:
			literals.setLiteral(static_cast<float>(std::strtod(input.c_str(), NULL)));
			break ;
		case DOUBLE:
			literals.setLiteral(std::strtod(input.c_str(), NULL));
			break;
		case NAN_F:
			literals.setLiteral(std::numeric_limits<float>::quiet_NaN());
			break;
		case INF_F:
			literals.setLiteral(std::numeric_limits<float>::infinity());
			break;
		case N_INF_F:
			literals.setLiteral(-std::numeric_limits<float>::infinity());
			break;
		case NAN_D:
			literals.setLiteral(std::numeric_limits<double>::quiet_NaN());
			break;
		case INF_D:
			literals.setLiteral(std::numeric_limits<double>::infinity());
			break;
		case NEG_INF_D:
			literals.setLiteral(-std::numeric_limits<double>::infinity());
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


Literals::Literals( void ) : _a(static_cast<char>(0)), _i(0),
	_f(static_cast<float>(0)), _d(static_cast<double>(0))
{

}


void	Literals::setLiteral( char a )
{
	std::cout << "char: " << _a << std::endl;

	int	i = static_cast<int>(a);
	std::cout << "int: " << i << std::endl;

	float	f = static_cast<float>(a);
	std::cout << "float: " << f << 'f' << std::endl;

	double	d = static_cast<double>(a);
	std::cout << "double: " << d << std::endl;
}


void	Literals::setLiteral( int i )
{
	if (i < 0) {
		std::cout << "char: Impossible" << std::endl;
	} else if (i >= 32 && i <= 126) {
		char	a = static_cast<char>(i);
		std::cout << "char: " << _a << std::endl;
	} else if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min()) {
		std::cout << "char: Overflow" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}

	_i = i;
	std::cout << "int: " << _i << std::endl;

	_f = static_cast<float>(i);
	std::cout << "float: " << _f << 'f' << std::endl;

	_d = static_cast<double>(i);
	std::cout << "double: " << _d << std::endl;
}

void	Literals::setLiteral( float f )
{
	if (f < 0)
	if (f >= 32 && f <= 126) {
		_a = static_cast<char>(f);
		std::cout << "char: " << _a << std::endl;
	} else if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min()) {
		std::cout << "char: Overflow" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}

	_i = static_cast<int>(f);
	std::cout << "int: " << _i << std::endl;

	_f = f;
	std::cout << "float: " << _f << 'f' << std::endl;

	_d = static_cast<double>(f);
	std::cout << "double: " << _d << std::endl;
}

void	Literals::setLiteral( double d )
{
	if (i >= 32 && i <= 126) {
		char c = static_cast<char>(i);
		std::cout << "char: " << c << std::endl;
	} else if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min()) {
		std::cout << "char: Overflow" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}

	_i = i;
	std::cout << "int: " << _i << std::endl;

	_f = static_cast<float>(i);
	std::cout << "float: " << _f << 'f' << std::endl;

	_d = static_cast<double>(i);
	std::cout << "double: " << _d << std::endl;
}