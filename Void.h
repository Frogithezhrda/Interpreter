#pragma once
#include "Type.h"


class Void : public Type
{
public:
	//constructor with value
	Void();
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

};
