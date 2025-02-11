#include "Type.h"
#include "InterpreterException.h"
#include "Parser.h"
#include <iostream>
#include "NameErrorException.h"
#include "TypeException.h"

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Omer Saban"


int main(int argc,char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string;
	Type* type = nullptr;
	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);
	//i have a small bug with the syntax erros
	while (input_string != "quit()")
	{
		//trying to find the exception
		try
		{
			// parsing command
			type = Parser::parseString(input_string);
			std::cout << type->toString() << std::endl;
			if (type->isTemp())
			{
				delete type;
			}
		}
		catch (const TypeException& exception)
		{
			std::cout << exception.what() << std::endl; //printing excpetion
		}
		catch (const NameErrorExcepetion& exception)
		{
			std::cout << exception.what() << std::endl; //printing excpetion
		}
		catch (const std::exception& exception)
		{
			std::cout << exception.what() << std::endl; //printing excpetion
		}

		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}
	//cleaning the variables
	Parser::cleanVariables();
	return 0;
}
