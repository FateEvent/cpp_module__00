#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
//	Bureaucrat	larry("Larry", 101);
	Bureaucrat	jean("Jean", 56);
	Bureaucrat	none("Chief", 1);

	AForm	form;
	AForm	form2(form);
	AForm	b32( "B32 form", 100, 67 );
	AForm	b45( b32 );
	jean.signForm(b32);
	std::cout << b32.getIsSigned() << std::endl;
//	larry.signForm(b45);
	none.signForm(b32);
//	none.signForm(b45);

	std::cout << form2 << "\n" << form2.getName() << std::endl;
}
