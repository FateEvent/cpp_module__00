#ifndef DOG_H
# define DOG_H

# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Brain;

class Dog : public AAnimal
{
public:
	Dog( void );
	Dog( const Dog &other );
	~Dog( void );
	Dog &			operator = ( const Dog &other );
	virtual void	makeSound( void ) const;
	Brain &			getBrain( void ) const;

private:
	Brain			*_brain;
};

#endif
