#pragma once
#include "Type.h"

class Text : public Type
{
public:
	Text(const Type* val);
	/*
	is printable or not
	input: none
	output: none
	*/
	virtual bool isPrintable() const override;
	/*
	makes it a string
	inpuit: none
	output: string
	*/
	virtual std::string toString() const override;
	/*
	getting the type of the variable
	input: none
	output: string
	*/
	virtual std::string getType() const override;
private:
	const Type* _val;
};
