#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	this->_type = "dog";
	this->_brain = new Brain();
	std::cout << "Oh, what a cute puppy!" << std::endl;
}


Dog::Dog( const Dog &other )
{
	if (*this != other);
	{
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(other->_brain);
		std::cout << "Here is your genetically modified puppy!" << std::endl;
	}
}


Dog::~Dog( void )
{
	std::cout << "Sadly, the puppy has gone..." << std::endl;
	delete this->_brain;
	this->_brain = NULL;
}


Dog &	Dog::operator = ( const Dog &other )
{
	if (this == &other)
		return (*this);
	this->_type = other._type;
	delete this->_brain;
	this->_brain = new Brain(other->_brain);
	std::cout << "Here is your genetically modified puppy!" << std::endl;
	return (*this);
}


void	Dog::makeSound( void ) const
{
	std::cout << "Woof woof!" << std::endl;
}

