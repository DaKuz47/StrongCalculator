#pragma once
#include "BinaryOperation.h"

class Addition : public BinaryOperation {
private:
	virtual double operation(double x, double y) override final {
		return x + y;
	}
public:
	Addition() : BinaryOperation{ "+", 0 }{};
};
