#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "Water.hpp"

class Character : public ICharacter
{
protected:
	std::string	_name;
	AMateria	*_stock[4];
	int			_index;

public:
	Character( void );
	Character( std::string const & name );
	Character(std::string const & name, AMateria* m);
	Character( const Character & other );
	virtual	~Character( void );
	Character & operator = ( const Character & other );
	virtual	std::string const & getName() const;
	virtual	void equip(AMateria* m);
	virtual	void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
	void setIndex( void );
	int getIndex( void ) const;

};

#endif