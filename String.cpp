#include "String.h"

String::String(const std::string& str)
{
	this->_val = str;
}

bool String::isPrintable() const
{
	return true;
}



std::string String::toString() const
{
	//checcking if they only appear twice
	if (_val.find("'") != std::string::npos)
	{
		return "\"" + _val + "\"";
	}
	else if (_val.find("\"") != std::string::npos)
	{
		//i changed it to mine it looks better if you want
		//return "'" + _val + "'";
		return _val;
	}
}

std::string String::getType() const
{
	return "str";
}

int String::getLength() const
{
	return _val.size() - 2;
}
