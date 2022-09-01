#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("shrubbery creation form", 145, 137),
	_target("the intern")
{

}


ShrubberyCreationForm::ShrubberyCreationForm( std::string const target ) : Form("shrubbery creation form", 145, 137),
	_target(target)
{

}


ShrubberyCreationForm::~ShrubberyCreationForm()
{

}


ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const& other ) : Form( other.getName(), other.getSignatureGrade(), other.getExecutionGrade() ),
	_target(other.getTarget())
{
	if (other.getIsSigned())
		this->setSignature();
}


ShrubberyCreationForm&	ShrubberyCreationForm::operator = ( const ShrubberyCreationForm& other )
{
	if (this == &other)
		return (*this);
	std::cout << "It's not possible to cross out elements from a form." << std::endl;
	std::cout << "Please, print a new proper and fresh form. Thank you." << std::endl;
	return (*this);
}


std::ostream&	operator << (std::ostream& os, const ShrubberyCreationForm& form)
{
	os << "Form: " << form.getName() << ", target: " << form.getTarget() << ", grade for signature: " << form.getSignatureGrade();
	os << ", grade for execution: " << form.getExecutionGrade() << ", signed: " << form.getIsSigned() << std::endl;
	return (os);
}


std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}


bool	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	try {
		if (!this->getIsSigned())
			throw BureauException("ShrubberyCreationForm::SignatureException");
		else
		{
			try {
				if (executor.getGrade() > this->getExecutionGrade())
					throw BureauException("ShrubberyCreationForm::GradeTooLowException");
				else
				{
					this->plantingTrees();
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
