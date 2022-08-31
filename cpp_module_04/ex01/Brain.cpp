#include "Brain.hpp"

Brain::Brain( void ) : _ideas()
{
	std::cout << "A new brain has been produced." << std::endl;
}


Brain::Brain( const Brain &other )
{
	int	i = 0;
	while (i++ < 100)
		this->_ideas[i] = other._ideas[i];
	std::cout << "A brain genetically modified has been produced." << std::endl;
}


Brain::~Brain( void )
{
	std::cout << "Psssss, the brain has deflated!" << std::endl;
}


Brain &	Brain::operator = ( const Brain &other )
{
	if (this == &other)
		return (*this);
	int	i = 0;
	while (i++ < 100)
		this->_ideas[i] = other._ideas[i];
	return (*this);
}


std::string	*Brain::getIdeas( void )
{
	return (this->_ideas);
}
