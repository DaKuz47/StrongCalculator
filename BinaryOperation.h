#pragma once
#include "Operation.h"

class BinaryOperation : public Operation {
private:
	virtual double operation(double x, double y) = 0;
public:
	BinaryOperation(std::string n = "", int p = 0) : Operation{ n, p } {};
	virtual void calculate(Stack<double, 30>& stack) override final {
		double x = stack.pop();
		double y = stack.pop();
		stack.push(operation(x, y));
	}
};