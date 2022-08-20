#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>
# include <string>

class WrongAnimal
{
public:
	WrongAnimal( void );
	WrongAnimal( std::string type );
	WrongAnimal( const WrongAnimal &other );
	~WrongAnimal( void );
	WrongAnimal &	operator = ( const WrongAnimal &other );
	void		makeSound( void ) const;
	std::string	getType( void ) const;

protected:
	std::string	_type;
};

#endif
