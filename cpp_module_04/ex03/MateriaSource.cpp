#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : _index(0)
{
	for (int i = 0; i < 4; i++)
		this->_stock[i] = NULL;
}


MateriaSource::MateriaSource( const MateriaSource & other )
{
	*this = other;
}


MateriaSource::~MateriaSource( void )
{

}


MateriaSource & MateriaSource::operator = ( const MateriaSource & other )
{
	if (this == &other)
		return (*this);
	MateriaSource *ms = new MateriaSource;
	int i = 0;
	while (i < 4)
	{
		if (ms->_stock[i]->getType() != "empty")
			delete ms->_stock[i];
		ms->_stock[i] = other._stock[i]->clone();
		i++;
	}
	return (*ms);
}


void MateriaSource::learnMateria(AMateria *m)
{
	if (this->_index > 3)
		std::cout << "Can't learn any more materias" << std::endl;
	else
	{
		this->_stock[this->_index] = m;
		this->_index++;
		std::cout << "Learnt " << m->getType() << " materia" << std::endl;
	}
}


AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4 && this->_stock[i]; i++)
	{
		if (type == this->_stock[i]->getType())
			return this->_stock[i]->clone();
	}
	return NULL;
}
