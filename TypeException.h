#pragma once
#include "InterpreterException.h"
#include <string>

class TypeException : InterpreterException
{
public:
	//excpetion constructor gets the name
	TypeException(const std::string& type, const std::string& func);
	//prints what happend
	virtual const char* what() const noexcept;
private:
	std::string _type;
	std::string _func;
	std::string _error;
};