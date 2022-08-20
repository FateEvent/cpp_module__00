#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	this->_type = "cat";
	std::cout << "Wow, what a beautiful kitten we have here!" << std::endl;
}


Cat::Cat( const Cat &other )
{
	*this = other;
	std::cout << "Wow, a new kitten genetically modified!" << std::endl;
}


Cat::~Cat( void )
{
	std::cout << "Sadly, the kitten has died..." << std::endl;
}


Cat &	Cat::operator = ( const Cat &other )
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}


void	Cat::makeSound( void ) const
{
	std::cout << "Meow meow!" << std::endl;
}
