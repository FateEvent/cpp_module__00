#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	signAndExecute(AForm *form)
{
	Bureaucrat	c3p0;
	Bureaucrat	chief("the boss", 1);
	if (form)
	{
		c3p0.signForm( *form );
		std::cout << *form << std::endl;
		chief.signForm( *form );
		std::cout << *form << std::endl;
		chief.executeForm( *form );
		std::cout << *form << std::endl;
		delete form;
	}
}

int	main()
{
	Intern		someRandomIntern;

	AForm					*rrf;
	AForm					*b15;
	AForm					*b32;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	b15 = someRandomIntern.makeForm("typing machine", "me");
	b32 = someRandomIntern.makeForm("presidential pardon", "Giacomo");

	signAndExecute(b32);
	signAndExecute(b15);
	signAndExecute(rrf);
}
