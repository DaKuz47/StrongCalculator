#pragma once
#include "BinaryOperation.h"

class Subtraction : public BinaryOperation {
private:
	virtual double operation(double x, double y) override final {
		return y - x;
	}
public:
	Subtraction() : BinaryOperation{ "-", 0 } {};
};
