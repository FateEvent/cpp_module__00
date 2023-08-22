#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( const ScavTrap &other );
	~ScavTrap( void );
	ScavTrap &  operator = ( const ScavTrap &other );
	void		attack( const std::string& target );
	void		guardGate( void );
};

#endif
