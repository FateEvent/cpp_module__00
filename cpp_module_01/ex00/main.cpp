#include "Zombie.hpp"

int main()
{
    Zombie  *fab;

    fab = newZombie("Fab");
    randomChump("Sam");
    std::cout << fab->getName() << ": Hello world!" << std::endl;
    fab->announce();
    delete fab;
    return 0;
}
