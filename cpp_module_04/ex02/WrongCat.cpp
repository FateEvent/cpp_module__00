#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
	this->_type = "cat";
	std::cout << "Wow, what a beautiful kitten we have here!" << std::endl;
}


WrongCat::WrongCat( const WrongCat &other )
{
	*this = other;
	std::cout << "Wow, a new kitten genetically modified!" << std::endl;
}


WrongCat::~WrongCat( void )
{
	std::cout << "Sadly, the kitten has died..." << std::endl;
}


WrongCat &	WrongCat::operator = ( const WrongCat &other )
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}


void	WrongCat::makeSound( void ) const
{
	std::cout << "Meow meow!" << std::endl;
}
