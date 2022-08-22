#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource( void );
	MateriaSource( const MateriaSource & other );
	virtual ~MateriaSource();
	MateriaSource & operator = ( const MateriaSource & other );
	virtual void learnMateria(AMateria *m);
	virtual AMateria* createMateria(std::string const & type);

protected:
	AMateria	*_stock[4];
	int			_index;
};

#endif