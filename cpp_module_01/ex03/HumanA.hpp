#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include <string>
# include "Weapon.hpp"


class HumanA
{
public:
	HumanA( std::string name, Weapon& type );
	void        attack( void );

private:
	std::string _name;
	std::string _weaponType;
};

#endif
