#include <iostream>
#include "Summator.h"
#include "Subtractor.h"
#include "CustomExpressionEvaluator.h"

int main()
{
    // Создать массив указателей на абстрактный класс обработки арифметических выражений.
// Например, так:
    ExpressionEvaluator* evaluators[3];

    evaluators[0] = new Subtractor(4);
    double sub_operands[] = { 10.5, 2.5, -3, 1.5 };
    evaluators[0]->setOperands(sub_operands, 4);
    
    evaluators[1] = new CustomExpressionEvaluator(6);
    double custom_operands[] = { 5, 15, -8, 1, 2, 3 };
    evaluators[1]->setOperands(custom_operands, 6);

    // и заполнить его данными вторым способом
    evaluators[2] = new Summator(3);
    evaluators[2]->setOperand(0, 1.5); 
    evaluators[2]->setOperand(1, -4);
    evaluators[2]->setOperand(2, 2.5);
    // проход в цикле по указателям evaluators
    // и вывод на консоль и в файл лога выражения (в консоли еще сам результат выражения)
    for (size_t i = 0; i < 3; ++i) // демонстрация полиморфизма
    {
        evaluators[i]->calculate();
        evaluators[i]->logToFile("Lab3.log");
        evaluators[i]->logToScreen();
    }

    for (size_t i = 0; i < 3; ++i) 
    {
        evaluators[i]->shuffle();
        evaluators[i]->shuffle(0, 2);
    }
    
    // Очистка динамической памяти
    for (int i = 0; i < 3; ++i ) 
    {
        delete evaluators[i];
    }
   
    return 0;
}

