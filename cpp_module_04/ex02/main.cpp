#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	AAnimal *arr[10];

	for (int i = 0; i < 5; i++)
		arr[i] = new Dog();
	for (int i = 5; i < 10; i++)
		arr[i] = new Cat();
	for (int i = 0; i < 10; i++)
		delete arr[i];

	const AAnimal* j = new Dog();
	const AAnimal* k = new Cat();

	// It's not possible to instantiate an object of an abstract class like the following:
	// const AAnimal* l = new AAnimal();

	delete j;	//should not create a leak
	delete k;

	Cat	kittyPaw;
	Brain	brain;

	brain.setIdea( "food" );
	brain.setIdea( "hugs" );
	kittyPaw.setBrain( brain );
	brain.displayIdeas();
	kittyPaw.displayIdeas();

	return (0);
}
