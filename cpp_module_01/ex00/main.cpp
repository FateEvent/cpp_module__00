#include "Zombie.hpp"

int main()
{
	Zombie	*fab;
	Zombie	zombie1("Foo");

	fab = newZombie("Fab");
	randomChump("Sam");
	std::cout << fab->getName() << ": Hello world!" << std::endl;
	fab->announce();
	delete fab;
	return 0;
}
