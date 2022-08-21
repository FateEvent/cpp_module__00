#ifndef ICE_H
# define ICE_H

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice( void );
	Ice( const Ice & other );
	virtual ~Ice( void );
	Ice & operator = ( const Ice & other );
	virtual Ice* clone() const;
	virtual void use(ICharacter & target);
};

#endif