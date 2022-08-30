#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
    std::string	_name;

public:
    Zombie( std::string name );
    Zombie( void );
    ~Zombie( void );
    std::string getName( void ) const;
    void		setName( std::string name );
    void		announce( void ) const;
};

Zombie	*newZombie( std::string name );
Zombie	*zombieHorde( int N, std::string name );
void	randomChump( std::string name );

#endif
