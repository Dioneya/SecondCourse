#include "CustomExpressionEvaluator.h"

CustomExpressionEvaluator::CustomExpressionEvaluator():ExpressionEvaluator() { }
CustomExpressionEvaluator::CustomExpressionEvaluator(int n) : ExpressionEvaluator(n) { }

double CustomExpressionEvaluator::calculate()
{
	expression = "";
	if (count_of_operands >= 2) {

		result = (operands[0] + operands[1]) / 2;
		expression +="( "+std::to_string(operands[0])+" plus "+ std::to_string(operands[1])+" ) divise by 2 ";

		for (int i = 2; i < count_of_operands; ++i) {

			expression += operands[i] < 0 ? " plus (" + std::to_string(operands[i]) + " ) " :  " plus "+std::to_string(operands[i]);
			result += operands[i];
		}
	}
	else if (count_of_operands == 1) {
		expression = std::to_string(operands[0]) + " divise by 2";
		result = operands[0] / 2;
	}	
	return result;
}

void CustomExpressionEvaluator::shuffle()
{
    
    int j = 0;
    double tmp = 0;
    for (int i = 0; i < count_of_operands; i++) {

        j = i;

        for (int k = i; k < count_of_operands; k++) {
            if (operands[j] > operands[k] && operands[k] > 0) {
                j = k;
            }
        }
        tmp = operands[i];
        operands[i] = operands[j];
        operands[j] = tmp;
    }

    calculate();
    logToScreen();

    /*for (int i = 0; i < count_of_operands; ++i) {

        std::cout << operands[i]<< " ";
    }
    std::cout << std::endl;*/
}

