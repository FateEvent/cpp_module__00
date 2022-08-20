#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : _type("default model")
{
	std::cout << "A new " << this->_type << " was born, allelujah!" << std::endl;
}


AAnimal::AAnimal( std::string type ) : _type(type)
{
	std::cout << "A new " << this->_type << " was born, allelujah!" << std::endl;
}


AAnimal::AAnimal( const AAnimal &other )
{
	*this = other;
	std::cout << "A new " << this->_type << " was born, allelujah!" << std::endl;
}


AAnimal::~AAnimal( void )
{
	std::cout << "So sad, the " << this->_type << " is dead!" << std::endl;
}


AAnimal &  AAnimal::operator = ( const AAnimal &other )
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}


void	AAnimal::makeSound( void ) const
{
	std::cout << "Kih kih kiiiiiiiih kiiiiiiiih kih kih!" << std::endl;
}


std::string	AAnimal::getType( void ) const
{
	return (this->_type);
}
