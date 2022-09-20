#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	fab( "Fab" );
//	FragTrap	diane( "Diane" );
	DiamondTrap	shanti( "Shanti" );
	DiamondTrap	kay( shanti );
	DiamondTrap	kitty;
	DiamondTrap	bruce;

	bruce.whoAmI();
//	fab.attack( "Shanti" );
//	diane.attack( "Fab" );
	fab.takeDamage( 30 );
//	diane.beRepaired( 100 );
//	diane.attack( "Fab" );
//	shanti.attack( "Diane" );
//	shanti.whoAmI();
	bruce.takeDamage(68);
	std::cout << "The robot " << bruce.getName() << " has " << bruce.getHitPoints() << " hit points left." << std::endl;
	bruce = fab;
	std::cout << "The robot " << bruce.getName() << " has " << bruce.getHitPoints() << " hit points left." << std::endl;
	std::cout << "The robot " << kitty.getName() << " has " << kitty.getHitPoints() << " hit points left." << std::endl;
	std::cout << "The robot " << kay.getName() << " has " << kay.getHitPoints() << " hit points left." << std::endl;

	return (0);
}
