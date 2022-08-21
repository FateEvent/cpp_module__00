#include "Character.hpp"

Character::Character( void ) : _name("black cultist")
{
	std::cout << "A " << this->_name << " has been created" << std::endl;
}


Character::Character(std::string const & name, AMateria* m) : _name(name)
{
	this->_stock[0] = m;
	std::cout << "A " << this->_name << " with " << this->_stock[0]->getType() << " has been created" << std::endl;
}


Character::Character( const Character & other )
{
	*this = other;
	std::cout << "A " << this->_name << "genetically modified with " << this->_stock[0]->getType() << " has been created" << std::endl;
}


Character::~Character( void )
{
	std::cout << "The " << this->_name << " has been destroyed" << std::endl;
}


Character & Character::operator = ( const Character & other )
{
	if (this == &other)
		return (*this);
	int i = 0;
	while (i < 4)
	{
		this->_stock[i] = other._stock[i]->clone();
		i++;
	}
	this->_name = other._name;
	return (*this);
}


std::string const & Character::getName() const
{
	return (this->_name);
}


void Character::equip(AMateria* m)
{
	size_t i = 0;
	while(i < 4)
	{
		if (this->_stock[i]->getType() == "empty")
		{
			this->_stock[i] = m;
			return ;
		}
		i++;
	}
}


void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	std::cout << "Materia " << this->_stock[idx]->getType() << " uneqipped" << std::endl;
	this->_stock[idx]->setType( "empty" );
}


void Character::use(int idx, Character& target);
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->_stock[idx]->getType() == "ice")
		this->Ice::use(target);
	if (this->_stock[idx]->getType() == "cure")
		this->Cure::use(target);
	else
		std::cout << "* sprays " << this->_stock[idx] << "on " << target.getName() << "'s wounds *" << std::endl;
	this->unequip( idx );
}
