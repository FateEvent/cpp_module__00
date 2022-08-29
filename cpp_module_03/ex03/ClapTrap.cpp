#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("default model"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " has been created by the RoboCorps factories!" << std::endl;
}


ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " has been created by the RoboCorps factories!" << std::endl;
}


ClapTrap::ClapTrap( std::string name, int hitPoints, int energyPoints, int attackDamage ) : _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
{
	std::cout << "ClapTrap " << this->_name << " has been created by the RoboCorps factories!" << std::endl;
}


ClapTrap::ClapTrap( const ClapTrap &other )
{
	*this = other;
	std::cout << "ClapTrap " << this->_name << " has been created by the RoboCorps factories!" << std::endl;
}


ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap " << this->_name << "'s memory has been deleted!" << std::endl;
}


ClapTrap &  ClapTrap::operator = ( const ClapTrap &other )
{
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}


void    ClapTrap::attack( const std::string& target )
{
	if (this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << " causing " << this->_attackDamage << " points of damage." << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " wasn't able to attack " << target;
		std::cout << " because of an important leak of energy." << std::endl;
	}
}

void    ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "ClapTrap " << this->_name << " has been attacked and has received ";
	std::cout << amount << " points of damage." << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
}


void    ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << " has been repaired of " << amount;
		std::cout << " hit points." << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " couldn't be repaired properly";
		std::cout << " because of an important leak of energy." << std::endl;
	}
}


std::string ClapTrap::getName( void ) const
{
	return (this->_name);
}


int ClapTrap::getHitPoints( void )
{
	return (this->_hitPoints);
}


int ClapTrap::getEnergyPoints( void )
{
	return (this->_energyPoints);
}


int ClapTrap::getAttackDamage( void )
{
	return (this->_attackDamage);
}
