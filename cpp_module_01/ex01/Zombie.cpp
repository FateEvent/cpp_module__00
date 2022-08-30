#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << this->_name << " has been transformed into a zombie." << std::endl;
}


Zombie::Zombie( void ) : _name("no name")
{
	std::cout << this->_name << " has been transformed into a zombie." << std::endl;
}


Zombie::~Zombie( void )
{
	std::cout << this->_name << " has been shot to death." << std::endl;
}


void	Zombie::announce( void ) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


std::string	Zombie::getName( void ) const
{
	return (this->_name);
}


void	Zombie::setName( std::string name )
{
	this->_name = name;
}
