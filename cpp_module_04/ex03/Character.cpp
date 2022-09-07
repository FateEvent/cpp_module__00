#include "Character.hpp"

Character::Character( void ) : _name("A black cultist"), _stock(), _index(0)
{
	for (int i = 0; i < 4; i++)
		this->_stock[i] = new Water();
}


Character::Character( std::string const & name ) : _name(name), _stock(), _index(0)
{
	for (int i = 0; i < 4; i++)
		this->_stock[i] = new Water();
}


Character::Character( std::string const & name, AMateria* m ) : _name(name), _stock(), _index(0)
{
	this->_stock[0] = m;
	for (int i = 1; i < 4; i++)
		this->_stock[i] = new Water();
}


Character::Character( const Character & other )
{
	for (int i = 0; i < 4; i++)
		this->_stock[i] = new Water();
	for (int i = 0; i < 4; i++)
	{
		delete this->_stock[i];
		this->_stock[i] = other._stock[i]->clone();
		i++;
	}
	this->_name = other._name;
}


Character::~Character( void )
{
	for (int i = 0; i < 4; i++)
		delete this->_stock[i];
}


Character & Character::operator = ( const Character & other )
{
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
		this->_stock[i] = new Water();
	for (int i = 0; i < 4; i++)
	{
		delete this->_stock[i];
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
	this->_stock[_index] = m;
	std::cout << "Materia " << this->_stock[_index]->getType() << " equipped" << std::endl;
	setIndex();
}


void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	std::cout << "Materia " << this->_stock[idx]->getType() << " unequipped" << std::endl;
	this->_stock[idx]->setType( "empty" );
}


void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->_stock[idx])
	{
		this->_stock[idx]->use( target );
		if (this->_stock[idx]->getType() != "empty")
			this->unequip( idx );
	}
}


void Character::setIndex( void )
{
	this->_index = (this->_index + 1) % 4;
}


int Character::getIndex( void ) const
{
	return (this->_index);
}
