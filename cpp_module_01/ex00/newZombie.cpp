#include "Zombie.hpp"

Zombie  *newZombie( std::string name )
{
    Zombie  *neuZombie;

    neuZombie = new Zombie(name);
    return (neuZombie);
}
