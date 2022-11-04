#pragma once
#include "BinaryOperation.h"

class Division : public BinaryOperation {
private:
	virtual double operation(double x, double y) override final {
		if (x == 0) {
			throw "������� �� ����";
		}
		return y / x;
	}
public:
	Division() : BinaryOperation{ "/", 1 } {};
};
