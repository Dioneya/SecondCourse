#pragma once
#include "ExpressionEvaluator.h"
class Summator: public ExpressionEvaluator
{
public:
	Summator();
	Summator(int);
	double calculate() override;

	void shuffle(size_t, size_t) override;
};

