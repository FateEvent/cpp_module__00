#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie			*neuZombie;
	unsigned int	i(0);

	neuZombie = new Zombie[N];
	while (i < N)
		neuZombie[i++].setName(name);
	return (neuZombie);
}
