#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap()
{
	this->FragTrap::_hitPoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 30;
	std::cout << "The DiamondTrap Mountain " << this->_name << " has risen from the depths of the RoboCorps factories!" << std::endl;
}


DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = name;
	std::cout << "The DiamondTrap Mountain " << this->_name << " has risen from the depths of the RoboCorps factories!" << std::endl;
}


DiamondTrap::DiamondTrap( const DiamondTrap &other )
{
    *this = other;
    std::cout << "The DiamondTrap Mountain " << this->_name << " has risen from the depths of the RoboCorps factories!" << std::endl;
}


DiamondTrap::~DiamondTrap( void )
{
    std::cout << "The DiamondTrap Mountain " << this->_name << " has fallen, sir!" << std::endl;
}


DiamondTrap &   DiamondTrap::operator = ( const DiamondTrap &other )
{
	if (this == &other)
        return (*this);
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}


void    DiamondTrap::attack( std::string const & target )
{
	this->ScavTrap::attack(target);
}


void    DiamondTrap::whoAmI( void )
{
	std::cout << "The DiamondTrap Mountain " << this->_name << ", " << ClapTrap::getName() << " reporting for duty." << std::endl;
}
