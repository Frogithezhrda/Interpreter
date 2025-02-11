#include "Text.h"

Text::Text(const Type* val)
{
	this->_val = val;
}

bool Text::isPrintable() const
{
	return true;
}

std::string Text::toString() const
{
	return "<type '" + this->_val->getType() + "'>";
}

std::string Text::getType() const
{
	return std::string();
}
