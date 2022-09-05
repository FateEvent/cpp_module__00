#include "Converter.hpp"

Converter::Converter( char a ) : _a(a), _i(static_cast<int>(a)),
	_f(static_cast<float>(a)), _d(static_cast<double>(a))
{
	std::cout << "char: " << _a << std::endl;

	std::cout << "int: " << _i << std::endl;
	
	std::cout << "float: " << _f << 'f' << std::endl;

	std::cout << "double: " << _d << std::endl;
}

Converter::Converter( int i ) : _i(i), _f(static_cast<float>(i)), _d(static_cast<double>(i))
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