#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	larry("Larry", 101);
	Bureaucrat	jean("Jean", 56);
	Bureaucrat	none;

	Form	form;
	Form	form2(form);
	Form	b32( "B32 form", 100, 67 );
	Form	b45( b32 );
	jean.signForm(b32);
	larry.signForm(b45);
	none.signForm(b32);
	none.signForm(b45);

	std::cout << form2 << "\n" << form2.getName() << std::endl;
}
