#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat	c3p0;
	Bureaucrat	jean("Jean", 56);
	Bureaucrat	none("Chief", 1);

	ShrubberyCreationForm	form( "garden" );
	PresidentialPardonForm	b15;
	RobotomyRequestForm		b32( "Giacomo" );
	c3p0.signForm(b32);
	c3p0.signForm(b15);
	c3p0.signForm(form);

	jean.executeForm(b32);
	jean.executeForm(b15);
	jean.executeForm(form);

	std::cout << b32 << std::endl;
	std::cout << b15 << std::endl;
	std::cout << form << std::endl;

	jean.signForm(b32);
	jean.signForm(b15);
	jean.signForm(form);
	none.signForm(b32);

	none.executeForm( b32 );
	none.executeForm( b15 );
	none.executeForm( form );
}
