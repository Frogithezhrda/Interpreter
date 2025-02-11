#pragma once
#include <string>

class Type
{
public:
	Type();
	/*
	is temp or not
	inpit: none
	output: is temp
	*/
	bool isTemp() const;
	/*
	setting temporary
	input: temp or not
	output: none
	*/
	void setTemp(const bool temp);
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
private:
	bool _isTemp;
};
