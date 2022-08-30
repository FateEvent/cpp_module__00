#ifndef BUREAUEXCEPTION_H
# define BUREAUEXCEPTION_H

# include <iostream>
# include <string>
# include <exception>

class BureauException : public std::exception
{
private:
	std::string	_msg;
public:
	explicit BureauException(const std::string& what_arg);
	virtual ~BureauException() throw();
	virtual const char* what() const throw();
};

#endif