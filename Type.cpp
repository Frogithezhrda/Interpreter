#include "Type.h"

Type::Type()
{
	this->_isTemp = false;
}


bool Type::isTemp() const
{
	return this->_isTemp;
}

void Type::setTemp(const bool temp)
{
	this->_isTemp = temp;
}
