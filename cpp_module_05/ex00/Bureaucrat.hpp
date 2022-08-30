#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>
# include <exception>
# include "BureauException.hpp"

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
public:
	Bureaucrat( void );
	Bureaucrat( std::string const name, int grade );
	Bureaucrat( Bureaucrat const& other );
	~Bureaucrat();
	std::string		getName( void ) const;
	int				getGrade( void ) const;
	Bureaucrat&		operator = ( const Bureaucrat &other );
	void			promote( void );
	void			demote( void );
	
	friend std::ostream&	operator << (std::ostream& os, const Bureaucrat& employee);
};

#endif