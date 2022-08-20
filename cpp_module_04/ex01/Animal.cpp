#include "Animal.hpp"

Animal::Animal( void ) : _type("default model")
{
	std::cout << "A new " << this->_type << " was born, allelujah!" << std::endl;
}


Animal::Animal( std::string type ) : _type(type)
{
	std::cout << "A new " << this->_type << " was born, allelujah!" << std::endl;
}


Animal::Animal( const Animal &other )
{
	*this = other;
	std::cout << "A new " << this->_type << " was born, allelujah!" << std::endl;
}


Animal::~Animal( void )
{
	std::cout << "So sad, the " << this->_type << " is dead!" << std::endl;
}


Animal &  Animal::operator = ( const Animal &other )
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}


void	Animal::makeSound( void ) const
{
	std::cout << "Kih kih kiiiiiiiih kiiiiiiiih kih kih!" << std::endl;
}


std::string	Animal::getType( void ) const
{
	return (this->_type);
}
