#include "NameErrorException.h"

NameErrorExcepetion::NameErrorExcepetion(const std::string& name)
{
	this->_name = "NameError : name '" + name + "' is not defined";
}

const char* NameErrorExcepetion::what() const noexcept
{
	return this->_name.c_str();
}
