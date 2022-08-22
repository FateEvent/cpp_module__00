#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("empty")
{
	std::cout << "AMateria default constructor called" << std::endl;
}


AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}


AMateria::AMateria( const AMateria & other )
{
	*this = other;
	std::cout << "AMateria copy constructor called" << std::endl;
}


AMateria::~AMateria( void )
{
	std::cout << "AMateria destructor called" << std::endl;
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
