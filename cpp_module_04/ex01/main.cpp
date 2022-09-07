#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	Animal	*arr[10];

	for (int i = 0; i < 5; i++)
		arr[i] = new Dog();
	for (int i = 5; i < 10; i++)
		arr[i] = new Cat();
	for (int i = 0; i < 10; i++)
		delete arr[i];

	const Animal* j = new Dog();
	const Animal* k = new Cat();

	delete j;	//should not create a leak
	delete k;

	Cat	kittyPaw;
	Dog	doggyPaw;
	Brain	brain;

	brain.setIdea( "food" );
	brain.setIdea( "hugs" );
	kittyPaw.setBrain( brain );
	doggyPaw.setBrain( brain );
	brain.displayIdeas();
	kittyPaw.displayIdeas();

	kittyPaw.~Cat();
	doggyPaw.displayIdeas();


	return (0);
}
