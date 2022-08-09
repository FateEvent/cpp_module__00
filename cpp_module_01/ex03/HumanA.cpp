#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name)
{
	_weaponType = weapon.getType();
}


void    HumanA::attack( void )
{
	std::cout << _name << " attacks with their " << _weaponType << std::endl;
}
