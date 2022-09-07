#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("empty")
{

}


AMateria::AMateria(std::string const & type) : _type(type)
{

}


AMateria::AMateria( const AMateria & other )
{
	*this = other;
}


AMateria::~AMateria( void )
{

}


AMateria & AMateria::operator = ( const AMateria & other )
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}


void AMateria::setType( std::string type )
{
	this->_type = type;
}


std::string const & AMateria::getType() const
{
	return (this->_type);
}


void AMateria::use(ICharacter & target)
{
	if (this->_type != "empty")
		std::cout << "* throws " << this->_type << " on " << target.getName() << " *" << std::endl;
	else
		std::cout << "* crosses their arms *" << std::endl;
}
