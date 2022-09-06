#include "Converter.hpp"

Converter::Converter( std::string const& input )
{
	Literals	literals;

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

enum type	Converter::typeDetecter(std::string const& str)
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


Converter::Literals::Literals( void ) : _a(static_cast<char>(0)), _i(0),
	_f(static_cast<float>(0)), _d(static_cast<double>(0))
{

}


void	Converter::Literals::setLiteral( char a )
{
	_a = a;
	std::cout << "char: " << _a << std::endl;

	_i = static_cast<int>(a);
	std::cout << "int: " << _i << std::endl;

	_f = static_cast<float>(a);
	std::cout << "float: " << _f << 'f' << std::endl;

	_d = static_cast<double>(a);
	std::cout << "double: " << _d << std::endl;
}


void	Converter::Literals::setLiteral( int i )
{
	if (i >= 32 && i <= 126) {
		_a = static_cast<char>(i);
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
/*
void	Converter::Literals::setLiteral( float f )
{
	char	*out;
	
	_a = static_cast<char>(i);
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

void	Converter::Literals::setLiteral( double d )
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
*/