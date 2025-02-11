#pragma once
#include "Sequence.h"
#include <list>

class List : public Sequence
{
public:
	List(std::string& list);
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
	/*
	getting the length of the sequence
	input: none
	output: length
	*/
	virtual int getLength() const override;

private:
	std::list<Type*> _val;
};