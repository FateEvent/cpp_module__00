#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap	thierry( "Thierry" );
	FragTrap	diane( "Diane" );
	FragTrap	nun( diane );

	diane.attack( "Thierry" );
	thierry.takeDamage( 67 );
	thierry.beRepaired( 40 );
	nun.attack( "Thierry");

	return (0);
}
