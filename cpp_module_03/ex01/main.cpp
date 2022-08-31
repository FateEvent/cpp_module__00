#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap	fab( "Fab" );
	ClapTrap	tan( "Tania" );
	ScavTrap	thierry( "Thierry" );
	ScavTrap	noName;

	noName = thierry;
	noName.guardGate();
	fab.attack( "Tania" );
	tan.beRepaired(5);
	thierry.attack("Fabio");

	return (0);
}
