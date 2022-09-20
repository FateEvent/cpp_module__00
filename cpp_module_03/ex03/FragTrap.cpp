#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "The FragTrap Destroyer " << this->_name << ", the final product of the ClapTrap robot family, has been created by the RoboCorps factories!" << std::endl;
}


FragTrap::FragTrap( std::string name ) : ClapTrap( name, 100, 100, 30 )
{
	std::cout << "The FragTrap Destroyer " << this->_name << ", the final product of the ClapTrap robot family, has been created by the RoboCorps factories!" << std::endl;
}


FragTrap::FragTrap( const FragTrap &other )
{
    *this = other;
    std::cout << "The FragTrap Destroyer " << this->_name << ", the final product of the ClapTrap robot family, has been created by the RoboCorps factories!" << std::endl;
}


FragTrap::~FragTrap( void )
{
    std::cout << "The FragTrap Destroyer " << this->_name << "'s chips have been crushed underfoot and thrown in the trash can!" << std::endl;
}


FragTrap &  FragTrap::operator = ( const FragTrap &other )
{
	if (this == &other)
        return (*this);
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}


void    FragTrap::attack( const std::string& target )
{
    if (this->_energyPoints && this->_hitPoints)
    {
        std::cout << "The FragTrap Destroyer " << this->_name << " attacks " << target;
        std::cout << " causing " << this->_attackDamage << " points of damage." << std::endl;
        this->_energyPoints--;
    }
    else
    {
        std::cout << "The FragTrap Destroyer " << this->_name << " wasn't able to attack " << target;
        std::cout << " because of an important leak of energy." << std::endl;
    }
}

void    FragTrap::highFivesGuys( void )
{
    std::cout << "Hey, guys, gimme five!" << std::endl;
}
