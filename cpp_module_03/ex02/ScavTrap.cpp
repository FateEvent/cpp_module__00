#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "The ScavTrap Stronghold " << this->_name << ", the latest evolution of the ClapTrap robot family, has been created by the RoboCorps factories!" << std::endl;
}


ScavTrap::ScavTrap( std::string name ) : ClapTrap( name, 100, 50, 20 )
{
	std::cout << "The ScavTrap Stronghold " << this->_name << ", the latest evolution of the ClapTrap robot family, has been created by the RoboCorps factories!" << std::endl;
}


ScavTrap::ScavTrap( const ScavTrap &other )
{
    *this = other;
    std::cout << "The ScavTrap Stronghold " << this->_name << ", the latest evolution of the ClapTrap robot family, has been created by the RoboCorps factories!" << std::endl;
}


ScavTrap::~ScavTrap( void )
{
    std::cout << "The ScavTrap Stronghold " << this->_name << "'s memory card has been erased and burnt!" << std::endl;
}


ScavTrap &  ScavTrap::operator = ( const ScavTrap &other )
{
	if (this == &other)
        return (*this);
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}


void    ScavTrap::attack( const std::string& target )
{
    if (this->_energyPoints && this->_hitPoints)
    {
        std::cout << "The ScavTrap Stronghold " << this->_name << " attacks " << target;
        std::cout << " causing " << this->_attackDamage << " points of damage." << std::endl;
        this->_energyPoints--;
    }
    else
    {
        std::cout << "The ScavTrap Stronghold " << this->_name << " wasn't able to attack " << target;
        std::cout << " because of an important leak of energy." << std::endl;
    }
}

void    ScavTrap::guardGate( void )
{
    std::cout << "The ScavTrap Stronghold " << this->_name << " entered the Gate Keeper mode!" << std::endl;
}
