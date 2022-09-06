#include "Brain.hpp"

Brain::Brain( void ) : _index(0)
{
	int	i(0);

	while (i++ < 100)
		_ideas[i] = "empty";
	std::cout << "A new brain has been produced." << _index << std::endl;
}


Brain::Brain( const Brain &other ) : _index(other._index)
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
	_index = other._index;
	while (i++ < 100)
		this->_ideas[i] = other._ideas[i];
	return (*this);
}


void	Brain::setIndex( void )
{
	std::cout << "bau" << std::endl;
	this->_index = (this->_index + 1) % 100;
}


int	Brain::getIndex() const
{
	return (this->_index);
}


std::string	*Brain::getIdeas( void )
{
	return (this->_ideas);
}


void	Brain::setIdea( std::string const& idea )
{
	std::cout << "cai" << std::endl;
//	std::cout << this->_index << std::endl;
	this->_ideas[0] = idea;
	setIndex();
}


void	Brain::displayIdeas( void ) const
{
	int	i(0);

	while (this->_ideas[i] != "empty")
		std::cout << this->_ideas[i] << std::endl;
}
