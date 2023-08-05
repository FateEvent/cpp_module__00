#include "PhoneBook.hpp"

int main ()
{
	PhoneBook	*addressBook;
	Contact		*newContact;
	std::string	input("empty string");
	int			exitValue(0);

	addressBook = new PhoneBook;
	std::cout << "Hi, this is your new phone book directly from the 80s!" << std::endl;
	std::cout << std::endl;
	std::cout << "Ah, what a great period, the 80s!" << std::endl;
	std::cout << std::endl;
	std::cout << "Please type:" << std::endl;
	std::cout << "            'ADD' to add a contact," << std::endl;
	std::cout << "            'SEARCH' to search for a contact," << std::endl;
	std::cout << "            'EXIT' to quit." << std::endl;
	std::cout << std::endl;
	std::cout << "Make your choice!" << std::endl;
	std::cout << std::endl;
	while (std::cin.fail() || !exitValue)
	{
		getline(std::cin, input);
		if (input.empty())
		{
			std::cout << std::endl;
			std::cout << "You're quitting the program." << std::endl;
			exitValue = 1;
		}
		else if (input == "ADD")
		{
			std::cout << std::endl;
			std::cout << "Please add a contact." << std::endl;
			addressBook->addContact(newContact->addEntry());
		}
		else if (input == "SEARCH")
		{
			std::cout << std::endl;
			std::cout << "Here are the registered contacts." << std::endl;
			addressBook->searchContact();
		}
		else if (input == "EXIT")
		{
			std::cout << std::endl;
			std::cout << "You're quitting the program." << std::endl;
			exitValue = 1;
		}
	}
	delete newContact;
	delete addressBook;
	return 0;
}
