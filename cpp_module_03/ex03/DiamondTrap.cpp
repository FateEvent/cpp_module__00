#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap("DiamC3P0_clap_name"), _name("default DiamC3P0")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "The DiamondTrap Mountain " << this->_name << " has risen from the depths of the RoboCorps factories!" << std::endl;
}


DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name + "_clap_name"), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "The DiamondTrap Mountain " << this->_name << " has risen from the depths of the RoboCorps factories!" << std::endl;
}


DiamondTrap::DiamondTrap( const DiamondTrap &other ) : ClapTrap(other.getName() + "_clap_name"), _name(other._name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
  std::cout << "An upgraded version of the DiamondTrap Mountain " << this->_name << " has risen from the depths of the RoboCorps factories!" << std::endl;
}


DiamondTrap::~DiamondTrap( void )
{
    std::cout << "The DiamondTrap Mountain " << this->_name << " has fallen, sir!" << std::endl;
}


DiamondTrap &   DiamondTrap::operator = ( const DiamondTrap &other )
{
	ClapTrap::_name = other.getName();
	_name = other._name;
	std::cout << "DiamondTrap " << _name << ": copy assignment operator called" << std::endl;
	return (*this);
}


void    DiamondTrap::attack( std::string const & target )
{
	this->ScavTrap::attack(target);
}


void    DiamondTrap::whoAmI( void )
{
	std::cout << "The DiamondTrap Mountain " << this->_name << ", " << ClapTrap::getName() << " reporting for duty." << std::endl;
	std::cout << "I have " << this->_hitPoints << " hit points, " << _energyPoints << " energy points and cause ";
	std::cout << this->_attackDamage << " attack damages." << std::endl;
}
