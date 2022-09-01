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
	bool					_isSigned;
	int	const				_signatureGrade;
	int	const				_executionGrade;

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

	virtual void			beSigned( Bureaucrat const& employee );
	virtual bool			execute( Bureaucrat const& executor ) const = 0;
};

std::ostream&	operator << (std::ostream& os, const AForm& form);

#endif