#include "Ice.hpp"

Ice::Ice( void ) : AMateria( "ice" )
{

}


Ice::Ice( const Ice & other )
{
	*this = other;
}


Ice::~Ice( void )
{

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
	return (new Ice(*this));
}


void Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}