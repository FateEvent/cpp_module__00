#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	this->_type = "cat";
	this->_brain = new Brain();
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
	delete this->_brain;
	this->_brain = NULL;
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
