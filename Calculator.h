#pragma once
#include <iostream>
#include "Stack.h"
#include <string>
#include <map>
#include <set>
#include "addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"

class Calculator
{
private:
	std::set<char> one_symbol_operations{ '-', '+', '/', '*', '(' };
	Stack<double, 30> stack_numbers;
	Stack<std::string, 30> stack_opr;
	std::map<std::string, Operation*> operation_list = {
		{"+", new Addition()},
		{"-", new Subtraction()},
		{"*", new Multiplication()},
		{"/", new Division()}
	};
	bool negative_num{ true };

public:
	Calculator() = default;
	~Calculator() {
		for (auto item : operation_list) {
			delete item.second;
		}
	}
	void loadLibraries() {

	}

	void reset();
	bool read(char c);
	double calculate();
	void calculateOneStep();
};

