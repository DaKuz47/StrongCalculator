#pragma once
#include "BinaryOperation.h"

class Multiplication : public BinaryOperation {
private:
	virtual double operation(double x, double y) override final {
		return x * y;
	}
public:
	Multiplication() : BinaryOperation{ "*", 1 } {};
};