#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("robotomy request form", 72, 45),
	_target("mayor's garden")
{

}


RobotomyRequestForm::RobotomyRequestForm( std::string const target ) : AForm("robotomy request form", 72, 45),
	_target(target)
{

}


RobotomyRequestForm::~RobotomyRequestForm()
{

}


RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const& other ) : AForm( other.getName(), other.getSignatureGrade(), other.getExecutionGrade() ),
	_target(other.getTarget())
{
	if (other.getIsSigned())
		this->setSignature();
}


RobotomyRequestForm&	RobotomyRequestForm::operator = ( const RobotomyRequestForm& other )
{
	if (this == &other)
		return (*this);
	std::cout << "It's not possible to cross out elements from a form." << std::endl;
	std::cout << "Please, print a new proper and fresh form. Thank you." << std::endl;
	return (*this);
}


std::ostream&	operator << (std::ostream& os, const RobotomyRequestForm& form)
{
	os << "Form: " << form.getName() << ", target: " << form.getTarget() << ", grade for signature: " << form.getSignatureGrade();
	os << ", grade for execution: " << form.getExecutionGrade() << ", signed: " << form.getIsSigned() << std::endl;
	return (os);
}


std::string	RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}


bool	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	try {
		if (!this->getIsSigned())
			throw BureauException("RobotomyRequestForm::SignatureException");
		else
		{
			try {
				if (executor.getGrade() > this->getExecutionGrade())
					throw BureauException("RobotomyRequestForm::GradeTooLowException");
				else
				{
					this->robotomize();
					return (1);
				}
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
