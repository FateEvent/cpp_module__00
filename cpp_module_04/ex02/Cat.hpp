#ifndef CAT_H
# define CAT_H

# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Brain;

class Cat : public AAnimal
{
public:
	Cat( void );
	Cat( const Cat &other );
	~Cat( void );
	Cat &					operator = ( const Cat &other );
	virtual void	makeSound( void ) const;
	void					setBrain( Brain const& brain );
	Brain &				getBrain( void ) const;
	void					displayIdeas( void ) const;

private:
	Brain					*_brain;
};

#endif
