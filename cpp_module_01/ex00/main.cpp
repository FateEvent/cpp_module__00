#include "Zombie.hpp"

int main()
{
	Zombie	unknown;
	Zombie	*fab;
	Zombie	zombie1("Foo");


	fab = newZombie("Fab");
	randomChump("Sam");
	unknown.announce();
	std::cout << fab->getName() << ": Hello world!" << std::endl;
	fab->announce();
	delete fab;
	return 0;
}
