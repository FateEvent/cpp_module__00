#include "Dog.hpp"

Dog::Dog( void ) : AAnimal()
{
	this->_type = "dog";
	this->_brain = new Brain();
	std::cout << "Oh, what a cute puppy!" << std::endl;
}


Dog::Dog( const Dog &other )
{
	this->_type = other._type;
	delete this->_brain;
	this->_brain = new Brain( other.getBrain() );
	std::cout << "Here is your genetically modified puppy!" << std::endl;
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
	this->_brain = new Brain( other.getBrain() );
	std::cout << "Here is your genetically modified puppy!" << std::endl;
	return (*this);
}


void	Dog::makeSound( void ) const
{
	std::cout << "Woof woof!" << std::endl;
}


Brain &	Dog::getBrain( void ) const
{
		return (*(this->_brain));
}


void	Dog::setBrain( Brain const& brain )
{
	*(this->_brain) = brain;
}

void	Dog::displayIdeas( void ) const
{
	this->_brain->displayIdeas();
}
