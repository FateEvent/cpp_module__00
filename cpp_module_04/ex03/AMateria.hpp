#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	_type;

public:
	AMateria( void );
	AMateria(std::string const & type);
	AMateria( const AMateria & other );
	virtual ~AMateria( void );
	void setType( std::string type );
	std::string const & getType() const;	//Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter & target);

private:
	AMateria & operator = ( const AMateria & other );
};

#endif