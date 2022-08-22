#include "Character.hpp"

Character::Character( void ) : _name("black cultist")
{
	std::cout << this->_name << " has been created" << std::endl;
}


Character::Character( std::string const & name ) : _name( name )
{
	std::cout << this->_name << " has been created" << std::endl;
}


Character::Character(std::string const & name, AMateria* m) : _name(name)
{
	this->_stock[0] = m;
	std::cout << this->_name << " with " << this->_stock[0]->getType() << " has been created" << std::endl;
}


Character::Character( const Character & other )
{	
	*this = other;
	std::cout << this->_name << "genetically modified with " << this->_stock[0]->getType() << " has been created" << std::endl;
}


Character::~Character( void )
{
	std::cout << this->_name << " has been destroyed" << std::endl;
}


Character & Character::operator = ( const Character & other )
{
	if (this == &other)
		return (*this);
	Character *character = new Character;
	int i = 0;
	while (i < 4)
	{
		if (character->_stock[i])
		{
			delete character->_stock[i];
			character->_stock[i] = other._stock[i]->clone();
		}
		i++;
	}
	character->_name = other._name;
	return (*character);
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
		if (this->_stock[i])
		{
			delete this->_stock[i];
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


void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->_stock[idx])
	{
		this->_stock[idx]->use( target );
		this->unequip( idx );
	}
}
