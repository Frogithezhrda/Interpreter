#pragma once
#include "Type.h"

class Sequence : public Type
{
public:
	Sequence();
	/*
	is printable or not
	input: none
	output: none
	*/
	virtual bool isPrintable() const = 0;
	/*
	makes as a string
	input: none
	output: string
	*/
	virtual std::string toString() const = 0;
	/*
	getting the type of the variable
	input: none
	output: string
	*/
	virtual std::string getType() const = 0;
	/*
	getting the length of the sequence
	input: none
	output: length
	*/
	virtual int getLength() const = 0;
private:

};