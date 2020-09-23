#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
class CustomExpressionEvaluator : public ExpressionEvaluator
{
public:
	CustomExpressionEvaluator();
	CustomExpressionEvaluator(int);
	double calculate() override;

	void shuffle() override;
	
};

