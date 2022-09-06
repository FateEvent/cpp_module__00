#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap    fab( "Fab" );
    ClapTrap    tan( "Tania" );
    ClapTrap    red( tan );
    ClapTrap    none;

    fab.attack( "Tania" );
    tan.beRepaired(5);
    red.attack( "Fabio" );
    none.takeDamage(100);
    none.beRepaired(10);

    return (0);
}
