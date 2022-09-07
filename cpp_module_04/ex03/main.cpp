#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Water.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Water());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	Character vero("Vero");
	Character izzy;
	
	tmp = src->createMateria("ice");
	vero.equip(tmp);
	tmp = src->createMateria("cure");
	izzy.equip(tmp);
	tmp = src->createMateria("ice");
	izzy.equip(tmp);
	tmp = src->createMateria("cure");
	vero.equip(tmp);

	Character jane = izzy;
	Character	joe(vero);

	izzy.use(0, *bob);
	jane.use(1, *bob);

	vero.use(0, *bob);
	joe.use(1, *me);

	delete bob;
	delete me;
	delete src;

	return 0;
}