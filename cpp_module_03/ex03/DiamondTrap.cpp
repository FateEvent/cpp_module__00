#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap("DiamC3P0_clap_name")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	this->_name = "default DiamC3P0";
	std::cout << "The DiamondTrap Mountain " << this->_name << " has risen from the depths of the RoboCorps factories!" << std::endl;
}


DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name + "_clap_name"), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "The DiamondTrap Mountain " << this->_name << " has risen from the depths of the RoboCorps factories!" << std::endl;
}


DiamondTrap::DiamondTrap( const DiamondTrap &other ) : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
    std::cout << "The DiamondTrap Mountain " << this->_name << " has risen from the depths of the RoboCorps factories!" << std::endl;
}


DiamondTrap::~DiamondTrap( void )
{
    std::cout << "The DiamondTrap Mountain " << this->_name << " has fallen, sir!" << std::endl;
}


DiamondTrap &   DiamondTrap::operator = ( const DiamondTrap &other )
{
	const ClapTrap& ct = other;
	ClapTrap::_name = ct.getName();
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "DiamondTrap " << _name << ": copy operator" << std::endl;
	return *this;
}


void    DiamondTrap::attack( std::string const & target )
{
	this->ScavTrap::attack(target);
}


void    DiamondTrap::whoAmI( void )
{
	std::cout << "The DiamondTrap Mountain " << this->_name << ", " << ClapTrap::getName() << " reporting for duty." << std::endl;
}
