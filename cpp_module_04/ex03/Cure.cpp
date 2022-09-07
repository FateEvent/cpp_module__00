#include "Cure.hpp"

Cure::Cure( void ) : AMateria( "cure" )
{

}


Cure::Cure( const Cure & other )
{
	*this = other;
}


Cure::~Cure( void )
{

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
	return (new Cure(*this));
}


void Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
