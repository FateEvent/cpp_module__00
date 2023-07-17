#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap( void );
	FragTrap( std::string name );
	FragTrap( const FragTrap &other );
	~FragTrap( void );
	FragTrap &	operator = ( const FragTrap &other );
	void		attack( const std::string& target );
	void		highFivesGuys( void );
};

#endif
