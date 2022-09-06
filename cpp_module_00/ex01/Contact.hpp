#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <new>
# include <cctype>

class Contact
{
	std::string	_phoneNumber;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_darkestSecret;
	int					_index;

public:
	Contact();
	Contact			*addEntry();
	void				displayEntry() const;
	void				setPhoneNumber(std::string phoneNumber);
	void				setFirstName(std::string firstName);
	void				setLastName(std::string lastName);
	void				setNickname(std::string nickname);
	void				setDarkestSecret(std::string darkestSecret);
	void				setIndex(int index);
	std::string	getPhoneNumber() const;
	std::string	getFirstName() const;
	int					getFirstNameLength() const;
	std::string	getLastName() const;
	int					getLastNameLength() const;
	std::string	getNickname() const;
	int					getNicknameLength() const;
	std::string	getDarkestSecret() const;
	int					getIndex() const;
	bool				isEmpty() const;
};

#endif
