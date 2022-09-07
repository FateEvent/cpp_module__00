#ifndef DOG_H
# define DOG_H

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Brain;

class Dog : public Animal
{
public:
	Dog( void );
	Dog( const Dog &other );
	~Dog( void );
	Dog &					operator = ( const Dog &other );
	virtual void	makeSound( void ) const;
	void					setBrain( Brain const& brain );
	Brain &				getBrain( void ) const;

private:
	Brain					*_brain;
};

#endif
