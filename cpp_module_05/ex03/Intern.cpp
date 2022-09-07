#include "Intern.hpp"

Intern::Intern( void )
{

}


Intern::~Intern( void )
{

}


AForm	*Intern::makeForm( std::string const& formName, std::string const& target )
{
	AForm	*form(nullptr);
	int		level = -1;
	
	std::string formTypes[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++) {
		if (!formTypes[i].compare(formName)) {
			level = i;
			break ;
		}
	}

	switch (level) {
		case 0:
			form = new ShrubberyCreationForm( target );
			std::cout << "The intern is creating the " << form->getName() << std::endl;
			return (form);
		case 1:
			form = new RobotomyRequestForm	( target );
			std::cout << "The intern is creating the " << form->getName() << std::endl;
			return (form);
		case 2:
			form = new PresidentialPardonForm( target );
			std::cout << "The intern is creating the " << form->getName() << std::endl;
			return (form);
		default:
			std::cout << "The Intern has rejected the demand for the " << formName << std::endl;
			return (NULL);
	}
}
