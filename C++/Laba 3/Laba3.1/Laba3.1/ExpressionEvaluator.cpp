#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator() 
{
    count_of_operands = 20;
    operands = new double[count_of_operands];
}

ExpressionEvaluator::ExpressionEvaluator(int n) 
{
    count_of_operands = n;
    operands = new double[count_of_operands];
}

ExpressionEvaluator::~ExpressionEvaluator()
{
    delete[] operands;
}

void ExpressionEvaluator::setOperand(size_t pos, double value)
{
    operands[pos] = value;
}

void ExpressionEvaluator::setOperands(double ops[], size_t n) 
{
    for (int i = 0; i < n ; ++i) {
        if (n <= count_of_operands) {
            operands[i] = ops[i];
        }
    }
}

void ExpressionEvaluator::logToScreen()
{
    for (int i = 0; i < count_of_operands; ++i){

        std::cout <<"Operand"<<i+1<<", ";
    }
    std::cout << std::endl << expression << std::endl << "Result = " << result << std::endl << std::endl;
}

void ExpressionEvaluator::logToFile(const std::string& filename)
{
    std::ofstream out;          // поток для записи
    out.open(filename+".txt", std::ios_base::app | std::ios_base::out); // окрываем файл для записи
    if (out.is_open()){

        for (int i = 0; i < count_of_operands; ++i){
            out << "Operand" << i + 1 << ", ";
        }
        out << std::endl << expression << std::endl << "Result = " << result << std::endl << std::endl;
    }
}


