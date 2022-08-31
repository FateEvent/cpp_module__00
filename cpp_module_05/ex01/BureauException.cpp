#include "BureauException.hpp"

BureauException::BureauException(const std::string& what_arg) : _msg(what_arg)
{

}


BureauException::~BureauException() throw()
{

}


const char	*BureauException::what() const throw()
{
	return (_msg.c_str());
}
