#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	const WrongAnimal* w = new WrongAnimal();
	const WrongAnimal* x = new WrongCat();

	std::cout << "Hi! I'm a " << x->getType() << " " << std::endl;
	x->makeSound(); //will output the animal sound!
	w->makeSound();

	delete w;
	delete x;

	const Dog	*doggy;

	doggy = new Dog;
	std::cout << "Hi! I'm a " << doggy->getType() << std::endl;
	delete doggy;

	return (0);
}