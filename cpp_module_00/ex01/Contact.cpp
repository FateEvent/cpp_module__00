#include "Contact.hpp"


Contact::Contact() : _phoneNumber("empty string"), _firstName("empty string"),
    _lastName("empty string"), _nickname("empty string"), _darkestSecret("empty string"), _index(0)
{

}


Contact *Contact::addEntry()
{
    Contact     *newContact;
    std::string input("");

    newContact = new Contact;
    std::cout << "Please insert the contact's phone number." << std::endl;
    while (input == "")
    {
        getline(std::cin, input);
        newContact->setPhoneNumber(input);
    }
    input = "";
    std::cout << "Please insert the contact's first name." << std::endl;
    while (input == "")
    {
        getline(std::cin, input);
        newContact->setFirstName(input);
    }
    input = "";
    std::cout << "Please insert the contact's last name." << std::endl;
    while (input == "")
    {
        getline(std::cin, input);
        newContact->setLastName(input);
    }
    input = "";
    std::cout << "Please insert the contact's nickname." << std::endl;
    while (input == "")
    {
        getline(std::cin, input);
        newContact->setNickname(input);
    }
    input = "";
    std::cout << "Please insert the contact's darkest secret." << std::endl;
    while (input == "")
    {
        getline(std::cin, input);
        newContact->setDarkestSecret(input);
    }
    return (newContact);
}


void    Contact::displayEntry() const
{
    std::cout << "Phone number: " << this->getPhoneNumber() << std::endl;
    std::cout << "First name: " << this->getFirstName() << std::endl;
    std::cout << "Last name: " << this->getLastName() << std::endl;
    std::cout << "Nickname: " << this->getNickname() << std::endl;
    std::cout << "Darkest secret: " << this->getDarkestSecret() << std::endl;
}


void    Contact::setPhoneNumber(std::string phoneNumber)
{
    this->_phoneNumber = phoneNumber;
}


void    Contact::setFirstName(std::string firstName)
{
    this->_firstName = firstName;
}


void    Contact::setLastName(std::string lastName)
{
    this->_lastName = lastName;
}


void    Contact::setNickname(std::string nickname)
{
    this->_nickname = nickname;
}


void    Contact::setDarkestSecret(std::string darkestSecret)
{
    this->_darkestSecret = darkestSecret;
}


void    Contact::setIndex(int index)
{
    this->_index = index;
}


std::string Contact::getPhoneNumber() const
{
    return (this->_phoneNumber);
}


std::string Contact::getFirstName() const
{
    return (this->_firstName);
}


int Contact::getFirstNameLength() const
{
    return (this->_firstName.length());
}


std::string Contact::getLastName() const
{
    return (this->_lastName);
}


int Contact::getLastNameLength() const
{
    return (this->_lastName.length());
}


std::string Contact::getNickname() const
{
    return (this->_nickname);
}


int Contact::getNicknameLength() const
{
    return (this->_nickname.length());
}


std::string Contact::getDarkestSecret() const
{
    return (this->_darkestSecret);
}


int Contact::getIndex() const
{
    return (this->_index);
}


bool    Contact::isEmpty() const
{
    return (_phoneNumber.empty() && _firstName.empty() && _lastName.empty()
            && _nickname.empty() && _darkestSecret.empty());
}
