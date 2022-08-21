#include "Ice.hpp"

Ice::Ice( void ) : AMateria( "ice" )
{
	std::cout << "Ice constructor called" << std::endl;
}


Ice::Ice( const Ice & other )
{
	*this = other;
	std::cout << "Ice copy constructor called" << std::endl;
}


Ice::~Ice( void )
{
	std::cout << "Ice destructor called" << std::endl;
}


Ice & Ice::operator = ( const Ice & other )
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}


Ice* Ice::clone() const
{
	Ice *clone;
	clone->_type = this->_type;
	return (clone);
}


void use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}