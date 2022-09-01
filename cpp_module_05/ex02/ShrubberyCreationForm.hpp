#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>
# include <fstream>
# include <string>
# include "BureauException.hpp"
# include "Bureaucrat.hpp"
# include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
	std::string								_target;

	ShrubberyCreationForm&					operator = ( const ShrubberyCreationForm &other );

public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string const target );
	ShrubberyCreationForm( ShrubberyCreationForm const& other );
	~ShrubberyCreationForm( void );
	std::string				getTarget( void ) const;
	int						plantingTrees( void ) const;

	virtual bool			execute( Bureaucrat const& executor ) const;
};

std::ostream&	operator << (std::ostream& os, const ShrubberyCreationForm& form);

#endif