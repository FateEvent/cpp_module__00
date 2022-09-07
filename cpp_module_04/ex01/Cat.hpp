#ifndef CAT_H
# define CAT_H

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Brain;

class Cat : public Animal
{
public:
	Cat( void );
	Cat( const Cat &other );
	~Cat( void );
	Cat &					operator = ( const Cat &other );
	virtual void	makeSound( void ) const;
	void					setBrain( Brain const& brain );
	Brain &				getBrain( void ) const;

private:
	Brain					*_brain;
};

#endif
