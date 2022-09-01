#ifndef AFORM_H
# define AFORM_H

# include <iostream>
# include <string>
# include "BureauException.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const		_name;
	static bool				_isSigned;
	int						_signatureGrade;
	int						_executionGrade;

	AForm&					operator = ( const AForm &other );

public:
	AForm( void );
	AForm( std::string const name, int signatureGrade, int executionGrade );
	AForm( AForm const& other );
	~AForm( void );

	std::string				getName( void ) const;
	int						getSignatureGrade( void ) const;
	int						getExecutionGrade( void ) const;
	bool					getIsSigned( void ) const;
	void					setSignature( void );

	void					beSigned( Bureaucrat& employee );

	friend std::ostream&	operator << (std::ostream& os, const AForm& form);
};

#endif