#ifndef ICHARACTER_H
# define ICHARACTER_H

# include <iostream>
# include <string>
# include "AMateria.hpp"

class ICharacter
{
public:
	virtual	~ICharacter( void ) {}
	virtual	std::string const & getName() const = 0;
	virtual	void equip(AMateria* m) = 0;
	virtual	void unequip(int idx) = 0;
	virtual	void use(int idx, ICharacter& target) = 0;
};

#endif