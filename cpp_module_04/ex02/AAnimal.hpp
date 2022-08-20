#ifndef AANIMAL_H
# define AANIMAL_H

# include <iostream>
# include <string>

class AAnimal
{
public:
	AAnimal( void );
	AAnimal( std::string type );
	AAnimal( const AAnimal &other );
	virtual			~AAnimal( void );
	AAnimal &		operator = ( const AAnimal &other );
	virtual void	makeSound( void ) const = 0;
	std::string		getType( void ) const;

protected:
	std::string	_type;
};

#endif
