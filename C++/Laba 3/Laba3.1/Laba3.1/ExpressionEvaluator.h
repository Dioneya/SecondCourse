#pragma once
#include "ILoggable.h"
#include <fstream>
#include <string>
#include <iostream>
#include "IShuffle.h"
class ExpressionEvaluator : public ILoggable, public IShuffle
{

protected:
	double* operands;
	double result = 0;
	int count_of_operands = 0;
	std::string expression = "";

public:
	
	void logToScreen() override;
	void logToFile(const std::string&) override;

	ExpressionEvaluator();
	ExpressionEvaluator(int n);
	~ExpressionEvaluator();

	virtual double calculate() = 0;

	void setOperand(size_t, double);
	void setOperands(double[], size_t);
};

