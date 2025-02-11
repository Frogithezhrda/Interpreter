#include "List.h"
#include <iostream>
#include "Helper.h"
#include <sstream>
#include <string>
#include "Parser.h"

List::List(std::string& list)
{
	std::istringstream listStream;
	std::string line = "";
	Type* type = nullptr;
	list = list.substr(1, list.size() - 2);
	Helper::trim(list);
	listStream.str(list);
	while (std::getline(listStream, line, ','))
	{
		Helper::trim(line);
		type = Parser::getType(line);
		if (!type)
		{
			throw SyntaxException();
		}
		_val.push_back(type);
	}
}

bool List::isPrintable() const
{
	return true;
}

std::string List::toString() const
{
	std::string list = "";
	for (const auto& currentVar : _val)
	{
		list += currentVar->toString() + ", ";
	}
	list.pop_back();
	list.pop_back();
	return '[' + list + ']';
}

std::string List::getType() const
{
	return "list";
}

int List::getLength() const
{
	return _val.size();
}
