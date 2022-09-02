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
	Harl	harl;
	void	(Harl::*e)( void );
	void	(Harl::*w)( void );
	void	(Harl::*i)( void );
	void	(Harl::*d)( void );

	e = &Harl::error;
	w = &Harl::warning;
	i = &Harl::info;
	d = &Harl::debug;
	if (level == "ERROR")
		(harl.*e)();
	else if (level == "WARNING")
		(harl.*w)();
	else if (level == "INFO")
		(harl.*i)();
	else if (level == "DEBUG")
		(harl.*d)();
	else
	{
		std::cout
			<< "[ Invalid entry ]:\n"
			<< "\"There are four levels, four damned levels!\n"
			<< "It's not like you can enter anything that passes through your mind!\n"
			<< "These levels are \"error\", \"warning\", \"info\" and \"debug\"!\"\n"
			<< std::endl;
	}
}
