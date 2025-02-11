#pragma once
#include "InterpreterException.h"

//prints what happend
class IndentationException : public InterpreterException
{
public:
	virtual const char* what() const noexcept;
};
