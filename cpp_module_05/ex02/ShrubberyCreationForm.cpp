#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("shrubbery creation form", 145, 137),
	_target("mayor's garden")
{

}


ShrubberyCreationForm::ShrubberyCreationForm( std::string const target ) : AForm("shrubbery creation form", 145, 137),
	_target(target)
{

}


ShrubberyCreationForm::~ShrubberyCreationForm()
{

}


ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const& other ) : AForm( other.getName(), other.getSignatureGrade(), other.getExecutionGrade() ),
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