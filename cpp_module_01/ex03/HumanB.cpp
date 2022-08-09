#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name)
{

}


void    HumanB::setWeapon( Weapon& weapon )
{
	_weaponType = weapon.getType();
}


void    HumanB::attack( void )
{
	std::cout << _name << " attacks with their " << _weaponType << std::endl;
}
