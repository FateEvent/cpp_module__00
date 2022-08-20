#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("default model")
{
	std::cout << "A new " << this->_type << " was born, allelujah!" << std::endl;
}


WrongAnimal::WrongAnimal( std::string type ) : _type(type)
{
	std::cout << "A new " << this->_type << " was born, allelujah!" << std::endl;
}


WrongAnimal::WrongAnimal( const WrongAnimal &other )
{
	*this = other;
	std::cout << "A new " << this->_type << " was born, allelujah!" << std::endl;
}


WrongAnimal::~WrongAnimal( void )
{
	std::cout << "So sad, the " << this->_type << " is dead!" << std::endl;
}


WrongAnimal &  WrongAnimal::operator = ( const WrongAnimal &other )
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}


void	WrongAnimal::makeSound( void ) const
{
	std::cout << "Kih kih kiiiiiiiih kiiiiiiiih kih kih!" << std::endl;
}


std::string	WrongAnimal::getType( void ) const
{
	return (this->_type);
}
