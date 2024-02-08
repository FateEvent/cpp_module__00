#include "PhoneBook.hpp"


PhoneBook::PhoneBook() : _contactArr(), _nextIndex(0) {}


void	PhoneBook::addContact(Contact *entry)
{
	this->_contactArr[this->_nextIndex] = *entry;
	this->_contactArr[this->_nextIndex].setIndex(this->_nextIndex);
	this->setNextIndex();
	std::cout << "Your contact has been correctly added." << std::endl;
}


int	PhoneBook::getNextIndex(void) const
{
	return (this->_nextIndex);
}


void	PhoneBook::setNextIndex(void)
{
	this->_nextIndex = (this->_nextIndex + 1) % 8;
}


static void	headerDisplay(void)
{
	std::cout.setf ( std::ios::right, std::ios::adjustfield );
	std::cout.width (10);
	std::cout << "index" << " | ";
	std::cout.width (10);
	std::cout << "first name" << " | ";
	std::cout.width (10);
	std::cout << "last name" << " | ";
	std::cout.width (10);
	std::cout << "nickname" << std::endl;
}

void    PhoneBook::searchContact(void)
{
	std::string     temp("empty string");
	unsigned int    i(0);
	int             input(-1);

	headerDisplay();
	while (i < 8 && this->_contactArr[i].getFirstName() != "empty string" && !std::cin.eof())
	{
		std::cout.setf ( std::ios::dec, std::ios::basefield );
		std::cout.setf ( std::ios::showbase );
		std::cout.width (10);
		std::cout << this->_contactArr[i].getIndex() << " | ";
		std::cout.setf ( std::ios::right, std::ios::adjustfield );
		std::cout.width (10);
		if (this->_contactArr[i].getFirstNameLength() <= 10)
			std::cout << this->_contactArr[i].getFirstName() << " | ";
		else
		{
			 temp = this->_contactArr[i].getFirstName().substr(0, 10);
			 temp[9] = '.';
			 std::cout << temp << " | ";
		}
		std::cout.width (10);
		if (this->_contactArr[i].getLastNameLength() <= 10)
			std::cout << this->_contactArr[i].getLastName() << " | ";
		else
		{
			 temp = this->_contactArr[i].getLastName().substr(0, 10);
			 temp[9] = '.';
			 std::cout << temp << " | ";
		}
		std::cout.width (10);
		if (this->_contactArr[i].getNicknameLength() <= 10)
			std::cout << this->_contactArr[i].getNickname() << std::endl;
		else
		{
			 temp = this->_contactArr[i].getNickname().substr(0, 10);
			 temp[9] = '.';
			 std::cout << temp << std::endl;
		}
		i += 1;
	}
	if (i > 0)
	{
		std::cout << "Please, now insert the index of the entry you're looking for." << std::endl;
		std::cin >> input;
		while ((input < 0 || input >= i) && !std::cin.eof())
		{
			std::cin.clear();
			std::cout << "This is not the entry you are looking for." << std::endl;
			std::cin >> input;
		}
		this->_contactArr[input].displayEntry();
	}
}
