#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <string>
# include "BureauException.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const		_name;
	bool					_isSigned;
	int						_signatureGrade;
	int						_executionGrade;

	Form&					operator = ( const Form &other );

public:
	Form( void );
	Form( std::string const name, int signatureGrade, int executionGrade );
	Form( Form const& other );
	~Form( void );

	std::string				getName( void ) const;
	int						getSignatureGrade( void ) const;
	int						getExecutionGrade( void ) const;
	bool					getIsSigned( void ) const;

	void					beSigned( Bureaucrat employee );

	friend std::ostream&	operator << (std::ostream& os, const Form& form);
};

#endif