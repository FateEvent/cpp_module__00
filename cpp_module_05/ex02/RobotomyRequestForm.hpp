#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <iostream>
# include <string>
# include <random>
# include "BureauException.hpp"
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string				_target;

	RobotomyRequestForm&	operator = ( const RobotomyRequestForm &other );

public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string const target );
	RobotomyRequestForm( RobotomyRequestForm const& other );
	~RobotomyRequestForm( void );
	std::string				getTarget( void ) const;
	void					robotomize( void ) const;
	virtual void			beSigned( Bureaucrat const& employee );
	virtual void			execute( Bureaucrat const& executor ) const;
};

std::ostream&	operator << (std::ostream& os, const RobotomyRequestForm& form);
void			robotomize( const std::string& target );

#endif