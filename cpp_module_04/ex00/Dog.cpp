#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	this->_type = "dog";
	std::cout << "Oh, what a cute puppy!" << std::endl;
}


Dog::Dog( const Dog &other )
{
	*this = other;
	std::cout << "Here is your puppy genetically modified!" << std::endl;
}


Dog::~Dog( void )
{
	std::cout << "Sadly, the puppy has gone..." << std::endl;
}


Dog &	Dog::operator = ( const Dog &other )
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}


void	Dog::makeSound( void ) const
{
	std::cout << "Woof woof!" << std::endl;
}

