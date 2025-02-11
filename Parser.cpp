#include "Parser.h"
#include "Void.h"
#include "NameErrorException.h"
#include "Text.h"
#include "TypeException.h"

static std::unordered_map<std::string, Type*> _variables;


Type* Parser::parseString(std::string str)
{
	Type* type = nullptr;
	//if we start with the space than expceiption
	if (str[0] == ' ' || str[0] == '	' || str.empty())
	{
		throw IndentationException();
	}
	Helper::rtrim(str);
	if (!str.find("type(") && str[str.size() - 1] == ')')
	{
		//getting the substr for the type
		str = str.substr(5, str.size() - 1);
		//popping the )
		str.pop_back();
		type = getType(str);
		if (!type)
		{
			type = getVariableValue(str);
		}
		if (type)
		{
			//making it text so the toString will give you the type result
			type = new Text(type);
			type->setTemp(true);
			return type;
		}
	}
	else if(!str.find("del "))
	{
		str = str.substr(4, str.size());
		if (_variables[str])
		{
			//deleting from variables
			_variables.erase(str);
			type = new Void();
			type->setTemp(true);
			return type;
		}
	}
	else if (!str.find("len(") && str[str.size() - 1] == ')')
	{
		str = str.substr(4, str.size() - 1);
		//popping the )
		str.pop_back();
		type = getType(str);
		type == nullptr ? type = getVariableValue(str) : type;
		Sequence* typeSeq = dynamic_cast<Sequence*>(type);
		if (typeSeq)
		{
			Integer* length = new Integer(typeSeq->getLength());
			return (Type*)length;
		}
		throw TypeException(type->getType(), "len");
	}
	else if (str == "len" || str == "del" || str == "type")
	{
		type = new Void();
		type->setTemp(true);
		std::cout << "<built-in function " + str + ">";
		return type;
	}
	//gettng first the type if its valid
	type = getType(str);
	if (!type)
	{
		//making the assignment
		if (makeAssignment(str))
		{
			type = new Void();
			type->setTemp(true);
		}
		else if (type = getVariableValue(str))
		{

		}
		else if (isLegalVarName(str))
		{
			throw NameErrorExcepetion(str);
		}
		else
		{
			throw SyntaxException();
		}
	}
	return type;
}

Type* Parser::getType(std::string& str)
{
	Helper::trim(str);
	Type* type = nullptr;
	//checking for each what it is
	if (str.empty())
	{
		return type;
	}
	if (Helper::isString(str))
	{
		type = new String(str);
	}
	else if (Helper::isBoolean(str))
	{
		type = new Boolean(str == "True");
	}
	else if (Helper::isInteger(str))
	{
		type = new Integer(stoi(str));
	}
	else if (Helper::isList(str))
	{
		type = new List(str);
	}
	//setting as temp
	if (type != nullptr)
	{
		type->setTemp(true);
	}
	return type;
}

bool Parser::isLegalVarName(std::string str)
{
	int i = 0;
	if (str.size() > 0)
	{
		//checking if the first is a digit
		if (Helper::isDigit(str[0]))
		{
			return false;
		}
	}
	for (i; i < str.size(); i++)
	{
		//checking if none exist than returning false
		if (!(Helper::isLetter(str[i]) || Helper::isDigit(str[i]) || Helper::isUnderscore(str[i])))
		{
			return false;
		}
	}
	return true;
}

bool Parser::makeAssignment(std::string str)
{
	int equalSign = str.find('=');
	std::string name = "";
	std::string value = "";
	std::string srcTypeStr = "";
	Type* type = nullptr;
	//checking if valid
	if (!str.empty() && str[0] != equalSign && str[str.size() - 1] != equalSign && equalSign != std::string::npos)
	{
		//getting the afrter
		name = str.substr(0, equalSign);
		value = str.substr(equalSign + 1, str.size() - equalSign + 1);
		Helper::rtrim(name);
		Helper::trim(value);
		//checking for illegal name
		if (!isLegalVarName(name))
		{
			throw SyntaxException();
		}
		//getting the type of the value
		type = getType(value);
		if (type)
		{
			//removing the temp
			type->setTemp(false);
			_variables[name] = type;
		}
		else if (isLegalVarName(value))
		{
			type = getVariableValue(value);
			if (type)
			{
				srcTypeStr = type->toString();
				if (Helper::isList(srcTypeStr))
				{
					//shallow copy for lists
					_variables[name] = type;
				}
				else
				{
					//deep copy 
					type = getType(srcTypeStr);
					type->setTemp(false);
					_variables[name] = type;
				}
			}
			else
			{
				throw SyntaxException();
			}
		}
		else
		{
			throw SyntaxException();
		}
		return true;
	}
	return false;
}

Type* Parser::getVariableValue(std::string str)
{
	//of the variables else throw name error excepetion
	return _variables[str];
}

void Parser::cleanVariables()
{
	//cleaning
	for (auto it = _variables.begin(); it != _variables.end(); it++)
	{
		delete it->second;
	}
}
