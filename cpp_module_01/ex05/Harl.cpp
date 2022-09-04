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
	void			(Harl::*functions[4])();
	std::string 	levels[4];
	int				i;
	
	functions[0] = &Harl::debug;
	functions[1] = &Harl::info;
	functions[2] = &Harl::warning;
	functions[3] = &Harl::error;

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

	for (i = 0; i < 4; i++) {
		if (levels[i] == level)
		{
			(this->*(functions[i]))();
			break ;
		}
	}
	if (i == 4)
	{
		std::cout
			<< "[ Invalid entry ]:\n"
			<< "\"There are four levels, four damned levels!\n"
			<< "It's not like you can enter anything that passes through your mind!\n"
			<< "These levels are \"error\", \"warning\", \"info\" and \"debug\"!\"\n"
			<< std::endl;
	}
}
