#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("C3PO, the protocol droid"), _grade(150)
{
	std::cout << _name << " has been hired with a grade of " << _grade << std::endl;
}

Bureaucrat::Bureaucrat( std::string const name, int grade ) : _name(name)
{
	try {
		if (grade < 1)
			throw BureauException("Bureaucrat::GradeTooHighException");
		else if (grade > 150)
			throw BureauException("Bureaucrat::GradeTooLowException");
		else
			_grade = grade;
	}
	catch (BureauException& e) {
		std::cerr << e.what() << std::endl;
		_grade = 150;
	}
	std::cout << _name << " has been hired with a grade of " << _grade << std::endl;
}


Bureaucrat::Bureaucrat( Bureaucrat const& other ) : _name(other._name), _grade(other._grade)
{
	std::cout << _name << " has been hired with a grade of " << _grade << std::endl;
}


Bureaucrat::~Bureaucrat()
{
	std::cout << _name << " has been fired." << std::endl;
}


std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}


int	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}


Bureaucrat&	Bureaucrat::operator = ( const Bureaucrat& other )
{
	if (this == &other)
		return (*this);
	this->_grade = other._grade;
	return (*this);
}


std::ostream&	operator << (std::ostream& os, const Bureaucrat& employee)
{
	return (os << employee.getName() << ", bureaucrat grade: " << employee.getGrade());
}


void	Bureaucrat::promote( void )
{
	try {
		if (_grade - 1 < 1)
			throw BureauException("Bureaucrat::GradeTooHighException");
		else
			this->_grade--;
	}
	catch (BureauException& e) {
		std::cerr << e.what() << std::endl;
	}
}


void	Bureaucrat::demote( void )
{
	try {
		if (_grade + 1 > 150)
			throw BureauException("Bureaucrat::GradeTooLowException");
		else
			this->_grade++;
	}
	catch (BureauException& e) {
		std::cerr << e.what() << std::endl;
	}
}


void	Bureaucrat::signForm( Form& form )
{
	if (!form.getIsSigned())
	{
		form.beSigned( *this );
		if (form.getIsSigned())
			std::cout << this->getName() << " signed the " << form.getName() << std::endl;
		else
			std::cout << this->getName() << " couldn't sign the " << form.getName() << std::endl;
	}
	else
		std::cout << "The " << form.getName() << " is already signed" << std::endl;
}