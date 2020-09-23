#include "Summator.h"

Summator::Summator() : ExpressionEvaluator() { }

Summator::Summator(int n) : ExpressionEvaluator(n) { }

double Summator::calculate() 
{
	expression = "";
	for (int i = 0; i < count_of_operands; ++i) 
	{
		if (i != count_of_operands - 1)
			expression += operands[i] < 0 ? " ( "+std::to_string(operands[i]) +  " ) plus ": std::to_string(operands[i]) + " plus ";
		else
			expression += operands[i] < 0 ? " ( " + std::to_string(operands[i]) + " ) " : std::to_string(operands[i]);
		result += operands[i];
	}
	return result;
}

void  Summator::shuffle(size_t i, size_t j)
{

	double tmp = operands[i];
	operands[i] = operands[j];
	operands[j] = tmp;

	calculate();
	logToScreen();
}