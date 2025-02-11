#include "TypeException.h"

TypeException::TypeException(const std::string& type, const std::string& func)
{
	this->_func = func;
	this->_type = type;
	this->_error = "TypeError: object of type ‘" + _type + "’ has no " + _func + "().";
}

const char* TypeException::what() const noexcept
{
	return _error.c_str();
}
