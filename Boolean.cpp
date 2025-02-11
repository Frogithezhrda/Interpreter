#include "Boolean.h"

Boolean::Boolean(const bool boolean)
{
    this->_val = boolean;
}

bool Boolean::isPrintable() const
{
    return true;
}

std::string Boolean::toString() const
{
    return this->_val ? "True" : "False";
}

std::string Boolean::getType() const
{
    return "bool";
}
