#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat	jean("Jean", 56);
	Bureaucrat	none("Chief", 1);

	ShrubberyCreationForm	form( "garden" );
	PresidentialPardonForm	form2;
	RobotomyRequestForm		b32( "Giacomo" );
//	jean.signForm(b32);
	std::cout << b32.getIsSigned() << std::endl;
//	none.signForm(b32);

	std::cout << form2 << "\n" << form2.getName() << std::endl;
	for (int i = 0; i < 50; i++)
		form.execute( jean );
	b32.robotomize();
	form.plantingTrees();
}
