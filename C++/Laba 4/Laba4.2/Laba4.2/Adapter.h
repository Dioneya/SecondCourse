#pragma once
#include "IFormattable.h"
#include <typeinfo>
class Adapter : public IFormattable
{
public:
	Adapter() {}
	void prettyPrint(const IFormattable& object) override;
	std::string format() override;
};

