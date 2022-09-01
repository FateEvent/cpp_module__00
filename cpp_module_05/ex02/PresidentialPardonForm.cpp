#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("presidential pardon form", 25, 5),
	_target("the intern")
{

}


PresidentialPardonForm::PresidentialPardonForm( std::string const target ) : AForm("presidential pardon form", 25, 5),
	_target(target)
{

}


PresidentialPardonForm::~PresidentialPardonForm()
{

}


PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const& other ) : AForm( other.getName(), other.getSignatureGrade(), other.getExecutionGrade() ),
	_target(other.getTarget())
{
	if (other.getIsSigned())
		this->setSignature();
}


PresidentialPardonForm&	PresidentialPardonForm::operator = ( const PresidentialPardonForm& other )
{
	if (this == &other)
		return (*this);
	std::cout << "It's not possible to cross out elements from a form." << std::endl;
	std::cout << "Please, print a new proper and fresh form. Thank you." << std::endl;
	return (*this);
}


std::ostream&	operator << (std::ostream& os, const PresidentialPardonForm& form)
{
	os << "Form: " << form.getName() << ", target: " << form.getTarget() << ", grade for signature: " << form.getSignatureGrade();
	os << ", grade for execution: " << form.getExecutionGrade() << ", signed: " << form.getIsSigned() << std::endl;
	return (os);
}


std::string	PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}


void	PresidentialPardonForm::beSigned( Bureaucrat const& employee )
{
	this->AForm::beSigned(employee);
}


void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	try {
		if (!this->getIsSigned())
			throw BureauException("PresidentialPardonForm::SignatureException");
		else
		{
			try {
				if (executor.getGrade() > this->getExecutionGrade())
					throw BureauException("PresidentialPardonForm::GradeTooLowException");
				else
					this->forgive();
			}
			catch (BureauException& e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}
	catch (BureauException& e) {
		std::cerr << e.what() << std::endl;
	}
}
