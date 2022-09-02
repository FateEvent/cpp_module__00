#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout
		<< "[ DEBUG ]\n"
		<< "\"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
		<< "I really do!\"\n"
		<< std::endl;
}


void	Harl::info( void )
{
	std::cout
		<< "[ INFO ]\n"
		<< "\"I cannot believe adding extra bacon costs more money.\n"
		<< "You didn't put enough bacon in my burger!\n"
		<< "If you did, I wouldn't be asking for more!\"\n"
		<< std::endl;
}


void	Harl::warning( void )
{
	std::cout
		<< "[ WARNING ]\n"
		<< "\"I think I deserve to have some extra bacon for free.\n"
		<< "I've been coming for years whereas you started working here since last month.\"\n"
		<< std::endl;
}


void	Harl::error( void )
{
	std::cout
		<< "[ ERROR ]\n"
		<< "\"This is unacceptable!\n"
		<< "I want to speak to the manager now.\"\n"
		<< std::endl;
}


void	Harl::complain( std::string level )
{
	int	levelN = -1;
	void (Harl::*functions[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string complainLevels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++) {
		if (!complainLevels[i].compare(level)) {
			levelN = i;
			break ;
		}
	}

	switch (levelN) {
		case 0:
			(this->*(functions[0]))();
		case 1:
			(this->*(functions[1]))();
		case 2:
			(this->*(functions[2]))();
		case 3:
			(this->*(functions[3]))();
			break;
		default:
		{
			std::cout
				<< "[ Probably complaining about insignificant problems ]"
				<< std::endl;
			break;
		}
	}
}
