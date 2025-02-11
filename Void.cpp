#include "Void.h"

Void::Void()
{
}

bool Void::isPrintable() const
{
	return false;
}

std::string Void::toString() const
{
	return std::string();
}

std::string Void::getType() const
{
	return "void";
}
