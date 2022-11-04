#pragma once
#include "BinaryOperation.h"

class Division : public BinaryOperation {
private:
	virtual double operation(double x, double y) override final {
		return y / x;
	}
public:
	Division() : BinaryOperation{ "/", 1 } {};
};
