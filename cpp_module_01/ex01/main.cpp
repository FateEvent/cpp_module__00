#include "Zombie.hpp"

int main()
{
    Zombie          *horde;
    unsigned int    i;

    i = 0;
    horde = zombieHorde(8, "Monstruo");
    while (i < 8)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return 0;
}
