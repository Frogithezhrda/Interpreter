#pragma once
#include "Type.h"

class Integer : public Type
{
public:
	Integer(const int integer);
	/*
	is printable or not
	input: none
	output: none
	*/
	bool isPrintable() const override;
	/*
	makes as a string
	input: none
	output: string
	*/
	std::string toString() const override;
	/*
	getting the type of the variable
	input: none
	output: string
	*/
	virtual std::string getType() const override;
private:
	int _val;
};
