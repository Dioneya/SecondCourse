#pragma once
#include "ExpressionEvaluator.h"
class Subtractor : public ExpressionEvaluator
{
public:
	Subtractor();
	Subtractor(int);
	double calculate() override;
};

