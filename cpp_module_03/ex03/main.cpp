#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	*fab = new DiamondTrap( "Fab" );
	FragTrap	diane( "Diane" );
	DiamondTrap	*shanti = new DiamondTrap( "Shanti" );
	DiamondTrap	*kay = new DiamondTrap( *shanti );
	DiamondTrap	*kitty = new DiamondTrap;
	DiamondTrap	*bruce = new DiamondTrap;

	// fab->highFivesGuys();
	bruce->whoAmI();
	fab->whoAmI();
	fab->attack( "Shanti" );
	// diane.attack( "Fab" );
	fab->takeDamage( 30 );
	// fab->guardGate();
	// diane.beRepaired( 100 );
	// diane.attack( "Fab" );
	shanti->attack( "Diane" );
	shanti->whoAmI();
	bruce->takeDamage(68);
	std::cout << "The robot " << fab->getName() << " has " << fab->getHitPoints() << " hit points left." << std::endl;
	std::cout << "The robot " << bruce->getName() << " has " << bruce->getHitPoints() << " hit points left." << std::endl;
	*bruce = *fab;
	std::cout << "The robot " << bruce->getName() << " has " << bruce->getHitPoints() << " hit points left." << std::endl;
	// std::cout << "The robot " << kitty->getName() << " has " << kitty->getHitPoints() << " hit points left." << std::endl;
	// std::cout << "The robot " << kay->getName() << " has " << kay->getHitPoints() << " hit points left." << std::endl;

	delete fab;
	delete shanti;
	delete kay;
	delete kitty;
	delete bruce;
	return (0);
}
