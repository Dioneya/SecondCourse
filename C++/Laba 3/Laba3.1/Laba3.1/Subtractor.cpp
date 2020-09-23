#include "Subtractor.h"

Subtractor::Subtractor() : ExpressionEvaluator() { }
Subtractor::Subtractor(int n) : ExpressionEvaluator(n) { }
 
double Subtractor::calculate()
{
	expression = "";
	result = operands[0];
	expression += operands[0] < 0 ? " ( " + std::to_string(operands[0]) + " ) " : std::to_string(operands[0]);
	for (int i = 1; i < count_of_operands; ++i)
	{
		expression += operands[i] < 0 ? " minus (" + std::to_string(operands[i]) + " ) " : " minus " + std::to_string(operands[i]);
		result -= operands[i];
	}
	return result;
}