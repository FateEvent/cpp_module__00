#ifndef WATER_H
# define WATER_H

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Water : public AMateria
{
public:
	Water( void );
	Water( const Water & other );
	virtual ~Water( void );
	Water & operator = ( const Water & other );
	virtual Water* clone() const;
};

#endif