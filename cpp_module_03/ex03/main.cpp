#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    ClapTrap    fab( "Fab" );
    FragTrap    diane( "Diane" );
    DiamondTrap shanti( "Shanti" );
    DiamondTrap kitty;
    ClapTrap    bruce;

    fab.attack( "Shanti" );
    diane.attack( "Fab" );
    fab.takeDamage( 30 );
    diane.beRepaired( 100 );
    diane.attack( "Fab" );
    shanti.whoAmI();
    bruce.takeDamage(68);
    std::cout << bruce.getName() << " has " << bruce.getHitPoints() << " hit points left." << std::endl;
    bruce = fab;
    std::cout << bruce.getName() << " has " << bruce.getHitPoints() << " hit points left." << std::endl;

    return (0);
}
