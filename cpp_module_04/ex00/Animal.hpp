#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <string>

class Animal
{
public:
	Animal( void );
	Animal( std::string type );
	Animal( const Animal &other );
	~Animal( void );
	Animal &		operator = ( const Animal &other );
	virtual void	makeSound( void ) const;
	std::string		getType( void ) const;

protected:
	std::string	_type;
};

#endif
