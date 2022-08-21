#ifndef CURE_H
# define CURE_H

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	Cure( void );
	Cure( const Cure & other );
	virtual ~Cure( void );
	Cure & operator = ( const Cure & other );
	virtual Cure* clone() const;
	virtual void use(ICharacter & target);
};

#endif