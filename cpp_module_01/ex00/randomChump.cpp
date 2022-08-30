#include "Zombie.hpp"

void	randomChump( std::string name )
{
	Zombie	*neuZombie;

	neuZombie = newZombie(name);
	neuZombie->announce();
	delete neuZombie;
}
