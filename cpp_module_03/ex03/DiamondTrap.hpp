#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include <iostream>
# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap( void );
	DiamondTrap( std::string name );
	DiamondTrap( const DiamondTrap &other );
	~DiamondTrap( void );
	DiamondTrap &	operator = ( const DiamondTrap &other );
	void			attack( std::string const & target );
	void			whoAmI( void );

private:
	std::string _name;
};

#endif
