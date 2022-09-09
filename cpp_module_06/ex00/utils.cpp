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

enum type	numericValuesHandler(std::string const& input)
{
	int	i = 0;
	int	dotCount = 0;

	if (input[0] == '-' && input[1])
		i++;
	if (input[i] == '.' && (input[i + 1] == 'f' || input[i + 1] == 0))
		return (UNKNOWN);
	while (input[i] == '.' || std::isdigit(input[i]))
	{
		if (input[i] == '.')
			dotCount++;
		if (dotCount > 1)
			return (UNKNOWN);
		i++;
	}
	if (!input[i])
	{
		if (dotCount == 1)
			return (DOUBLE);
		return (UNKNOWN);
	}
	else if (input[i] == 'f' && !input[i + 1] && dotCount == 1)
		return (FLOAT);
	return (UNKNOWN);
}

const char	*printDotZero(double number)
{
	if (number - static_cast<int>(number) == 0.0)
		return (".0");
	return ("");
}