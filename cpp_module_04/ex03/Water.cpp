#include "Water.hpp"

Water::Water( void ) : AMateria( "water" )
{

}


Water::Water( const Water & other )
{
	*this = other;
}


Water::~Water( void )
{

}


Water & Water::operator = ( const Water & other )
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}


Water* Water::clone() const
{
	return (new Water(*this));
}
