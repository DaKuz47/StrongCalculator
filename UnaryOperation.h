#pragma once
#include "Operation.h"

class UnaryOperation : public Operation {
private:
	virtual double operation(double x) = 0;
public:
	UnaryOperation(std::string n = "", int p = 2) : Operation{n, p} {};
	virtual void calculate(Stack<double, 30>& stack) override final {
		double x = stack.pop();
		stack.push(operation(x));
	}
};