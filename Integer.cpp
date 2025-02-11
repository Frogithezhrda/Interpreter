#include "Integer.h"
#include "Helper.h"

Integer::Integer(const int integer)
{
    this->_val = integer;
}

bool Integer::isPrintable() const
{
    return true;
}

std::string Integer::toString() const
{
    return std::to_string(this->_val);
}

std::string Integer::getType() const
{
    return "int";
}
