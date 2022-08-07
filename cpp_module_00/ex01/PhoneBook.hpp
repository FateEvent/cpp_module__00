#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"

class   PhoneBook
{
    Contact _contactArr[8];
    int     _nextIndex;

public:
    PhoneBook();
    void    addContact(Contact *entry);
    void    searchContact(void);
    void    setNextIndex(void);
    int     getNextIndex(void) const;
};

#endif
