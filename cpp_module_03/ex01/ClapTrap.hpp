#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>

class ClapTrap
{
public:
    ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( std::string name, int hitPoints, int energyPoints, int attackDamage );
	ClapTrap( const ClapTrap &other );
    ~ClapTrap( void );
    ClapTrap &  operator = ( const ClapTrap &other );
	void        attack( const std::string& target );
    void        takeDamage( unsigned int amount );
    void        beRepaired( unsigned int amount );
    std::string getName( void )  const;
    int         getHitPoints( void );
    int         getEnergyPoints( void );
    int         getAttackDamage( void );

protected:
	std::string _name;
	int         _hitPoints;
	int         _energyPoints;
	int         _attackDamage;
};

#endif
