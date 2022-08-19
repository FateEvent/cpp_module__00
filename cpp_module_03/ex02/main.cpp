#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap    fab( "Fab" );
    ClapTrap    tan( "Tania" );
    ScavTrap    thierry( "Thierry" );
    FragTrap    diane( "Diane" );

    fab.attack( "Tania" );
    diane.attack( "Thierry" );
    diane.attack( "Thierry" );
    thierry.attack( "Diane" );
    thierry.beRepaired( 40 );
    diane.attack( "Thierry" );
    diane.beRepaired( 100 );
    tan.beRepaired(5);
    thierry.attack("Fabio");
    diane.attack( "Thierry" );

    return (0);
}
