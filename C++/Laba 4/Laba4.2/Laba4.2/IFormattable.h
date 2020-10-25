#pragma once
#include <iostream>
#include <string>
class IFormattable
{
	virtual std::string format() = 0;
	virtual void prettyPrint(const IFormattable& object) = 0;
};

