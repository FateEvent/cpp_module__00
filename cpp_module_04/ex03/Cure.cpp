#include "Cure.hpp"

Cure::Cure( void ) : AMateria( "cure" )
{
	std::cout << "Cure constructor called" << std::endl;
}


Cure::Cure( const Cure & other )
{
	*this = other;
	std::cout << "Cure copy constructor called" << std::endl;
}


Cure::~Cure( void )
{
	std::cout << "Cure destructor called" << std::endl;
}


Cure & Cure::operator = ( const Cure & other )
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}


Cure* Cure::clone() const
{
	Cure *clone;
	clone->_type = this->_type;
	return (clone);
}


void use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
