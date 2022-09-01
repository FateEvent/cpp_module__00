#include "AForm.hpp"

bool	AForm::_isSigned = 0;

AForm::AForm( void ) : _name("standard form"),
	_signatureGrade(150), _executionGrade(150)
{

}


AForm::AForm( std::string const name, int signatureGrade, int executionGrade ) : _name(name),
	_signatureGrade(signatureGrade), _executionGrade(executionGrade)
{
	try {
		if (signatureGrade < 1)
			throw BureauException("Form::GradeTooHighException");
		else if (signatureGrade > 150)
			throw BureauException("Form::GradeTooLowException");
		else
			_signatureGrade = signatureGrade;
	}
	catch (BureauException& e) {
		std::cerr << e.what() << std::endl;
		_signatureGrade = 150;
	}
	try {
		if (executionGrade < 1)
			throw BureauException("Form::GradeTooHighException");
		else if (executionGrade > 150)
			throw BureauException("Form::GradeTooLowException");
		else
			_executionGrade = executionGrade;
	}
	catch (BureauException& e) {
		std::cerr << e.what() << std::endl;
		_executionGrade = 150;
	}
}


AForm::~AForm()
{

}


AForm::AForm( AForm const& other ) : _name(other._name), _signatureGrade(other._signatureGrade),
	_executionGrade(other._executionGrade)
{
	_isSigned = other._isSigned;
}


std::string	AForm::getName( void ) const
{
	return (this->_name);
}


int	AForm::getSignatureGrade( void ) const
{
	return (this->_signatureGrade);
}


int	AForm::getExecutionGrade( void ) const
{
	return (this->_executionGrade);
}


bool	AForm::getIsSigned( void ) const
{
	return (this->_isSigned);
}


void	AForm::setSignature( void )
{
	this->_isSigned = true;
}


AForm&	AForm::operator = ( const AForm& other )
{
	if (this == &other)
		return (*this);
	AForm	form;

	form._signatureGrade = other._signatureGrade;
	form._executionGrade = other._executionGrade;
	*this = form;
	return (*this);
}


void	AForm::beSigned( Bureaucrat& employee )
{
	try {
		if (employee.getGrade() > this->getSignatureGrade())
			throw BureauException("Form::GradeTooLowException");
		else
			this->_isSigned = true;
	}
	catch (BureauException& e) {
		std::cerr << e.what() << std::endl;
	}
}


std::ostream&	operator << (std::ostream& os, const AForm& form)
{
	os << "Form: " << form.getName() << ", grade for signature: " << form.getSignatureGrade();
	os << ", grade for execution: " << form.getExecutionGrade() << ", signed: " << form.getIsSigned() << std::endl;
	return (os);
}
