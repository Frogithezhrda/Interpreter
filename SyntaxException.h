#pragma once
#include <exception>

//prints what happend
class SyntaxException : public std::exception
{
	virtual const char* what() const noexcept;
};
