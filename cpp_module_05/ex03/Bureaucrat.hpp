#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>
# include <exception>
# include "BureauException.hpp"
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	std::string const	_name;
	int								_grade;

	Bureaucrat&				operator = ( const Bureaucrat &other );

public:
	Bureaucrat( void );
	Bureaucrat( std::string const name, int grade );
	Bureaucrat( Bureaucrat const& other );
	~Bureaucrat();
	std::string				getName( void ) const;
	int								getGrade( void ) const;
	void							promote( void );
	void							demote( void );
	void							signForm( AForm& form );
	void							executeForm(AForm const & form);
};

std::ostream&				operator << (std::ostream& os, const Bureaucrat& employee);

#endif