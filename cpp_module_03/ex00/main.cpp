#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap    fab( "Fab" );
    ClapTrap    tan( "Tania" );

    fab.attack( "Tania" );
    tan.beRepaired(5);

    return (0);
}
