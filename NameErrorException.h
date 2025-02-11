#pragma once
#include "InterpreterException.h"
#include <string>

class NameErrorExcepetion : InterpreterException
{
public:
	//excpetion constructor gets the name
	NameErrorExcepetion(const std::string& name);
	//prints what happend
	virtual const char* what() const noexcept;
private:
	std::string _name;
};