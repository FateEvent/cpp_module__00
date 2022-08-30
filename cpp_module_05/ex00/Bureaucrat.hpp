#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
public:
	Bureaucrat(/* args */);
	~Bureaucrat();
};

Bureaucrat::Bureaucrat(/* args */)
{
}

Bureaucrat::~Bureaucrat()
{
}
