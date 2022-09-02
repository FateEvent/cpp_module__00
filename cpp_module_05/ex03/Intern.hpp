#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include <string>
# include <exception>
# include "BureauException.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern( void );
	~Intern();
	AForm	*makeForm( std::string const& formName, std::string const& target );
};

#endif