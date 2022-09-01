#include "AForm.hpp"

AForm::AForm( void ) : _name("standard form"), _isSigned(0),
	_signatureGrade(150), _executionGrade(150)
{

}


AForm::AForm( std::string const name, int signatureGrade, int executionGrade ) : _name(name),
	_isSigned(0), _signatureGrade(signatureGrade), _executionGrade(executionGrade)
{
	try {
		if (signatureGrade < 1 || executionGrade < 1)
			throw BureauException("Form::GradeTooHighException");
		else if (signatureGrade > 150 || executionGrade > 150)
			throw BureauException("Form::GradeTooLowException");
	}
	catch (BureauException& e) {
		std::cerr << e.what() << std::endl;
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
	std::cout << "It's not possible to cross out elements from a form." << std::endl;
	std::cout << "Please, print a new proper and fresh form. Thank you." << std::endl;
	return (*this);
}


void	AForm::beSigned( Bureaucrat const& employee )
{
	try {
		if (employee.getGrade() > this->getSignatureGrade())
			throw BureauException("Form::GradeTooLowException");
		else
			this->setSignature();
	}
	catch (BureauException& e) {
		std::cerr << e.what() << std::endl;
	}
}


bool	AForm::execute(Bureaucrat const& executor) const
{
	try {
		if (!this->getIsSigned())
			throw BureauException("Form::SignatureException");
		else
		{
			try {
				if (executor.getGrade() > this->getExecutionGrade())
					throw BureauException("Form::GradeTooLowException");
				else
					return (1);
			}
			catch (BureauException& e) {
				std::cerr << e.what() << std::endl;
				return (0);
			}
		}
	}
	catch (BureauException& e) {
		std::cerr << e.what() << std::endl;
		return (0);
	}
}


std::ostream&	operator << (std::ostream& os, const AForm& form)
{
	os << "Form: " << form.getName() << ", grade for signature: " << form.getSignatureGrade();
	os << ", grade for execution: " << form.getExecutionGrade() << ", signed: " << form.getIsSigned() << std::endl;
	return (os);
}
