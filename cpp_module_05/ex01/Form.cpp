#include "Form.hpp"

bool	Form::_isSigned = 0;

Form::Form( void ) : _name("standard form"),
	_signatureGrade(150), _executionGrade(150)
{

}


Form::Form( std::string const name, int signatureGrade, int executionGrade ) : _name(name),
	_signatureGrade(signatureGrade), _executionGrade(executionGrade)
{
	try {
		if (signatureGrade < 1)
			throw BureauException("Form::GradeTooHighException");
		else if (signatureGrade > 150)
			throw BureauException("Form::GradeTooLowException");
	}
	catch (BureauException& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		if (executionGrade < 1)
			throw BureauException("Form::GradeTooHighException");
		else if (executionGrade > 150)
			throw BureauException("Form::GradeTooLowException");
	}
	catch (BureauException& e) {
		std::cerr << e.what() << std::endl;
	}
}


Form::~Form()
{

}


Form::Form( Form const& other ) : _name(other._name), _signatureGrade(other._signatureGrade),
	_executionGrade(other._executionGrade)
{
	_isSigned = other._isSigned;
}


std::string	Form::getName( void ) const
{
	return (this->_name);
}


int	Form::getSignatureGrade( void ) const
{
	return (this->_signatureGrade);
}


int	Form::getExecutionGrade( void ) const
{
	return (this->_executionGrade);
}


bool	Form::getIsSigned( void ) const
{
	return (this->_isSigned);
}


Form&	Form::operator = ( const Form& other )
{
	if (this == &other)
		return (*this);
	std::cout << "It's not possible to cross out elements from a form." << std::endl;
	std::cout << "Please, print a new proper and fresh form. Thank you." << std::endl;
	return (*this);
}


void	Form::beSigned( Bureaucrat const& employee )
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


std::ostream&	operator << (std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName() << ", grade for signature: " << form.getSignatureGrade();
	os << ", grade for execution: " << form.getExecutionGrade() << ", signed: " << form.getIsSigned() << std::endl;
	return (os);
}
