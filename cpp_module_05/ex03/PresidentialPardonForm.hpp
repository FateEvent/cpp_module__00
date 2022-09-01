#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include <iostream>
# include <fstream>
# include <string>
# include "BureauException.hpp"
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	std::string				_target;

	PresidentialPardonForm&	operator = ( const PresidentialPardonForm &other );

public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string const target );
	PresidentialPardonForm( PresidentialPardonForm const& other );
	~PresidentialPardonForm( void );
	std::string				getTarget( void ) const;
	void					forgive( void ) const;

	virtual bool			execute( Bureaucrat const& executor ) const;
};

std::ostream&	operator << (std::ostream& os, const PresidentialPardonForm& form);

#endif