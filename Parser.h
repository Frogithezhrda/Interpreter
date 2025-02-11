#pragma once
#include "InterpreterException.h"
#include "Type.h"
#include "Helper.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include "IndentationException.h"
#include "String.h"
#include "Boolean.h"
#include "Integer.h"
#include "Sequence.h"
#include "SyntaxException.h"
#include "List.h"

class Parser
{
public:
    /*
    parse string handles the string
    inpuit: str
    output: type as pointer
    */
    static Type* parseString(std::string str);
    /*
    getting the type
    inpuit: str
    output: type as pointer
    */
    static Type* getType(std::string& str);
    /*
    cleans the variables
    input: none
    output: none
    */
    static void cleanVariables();

private:
    /*
    checks if illegal name
    input: str
    output: none
    */
    static bool isLegalVarName(std::string str);
    /*U
    assigns a vaiable
    input: str
    output: is success
    */
    static bool makeAssignment(std::string str);
    /*
    returns if there is a vraiable value
    input: str
    output: variable value
    */
    static Type* getVariableValue(std::string str);
};
