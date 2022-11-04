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
#include <vector>
#include <windows.h>

class Calculator
{
private:
	Stack<double, 30> stack_numbers;
	Stack<std::string, 30> stack_opr;

	std::set<char> one_symbol_operations{ '-', '+', '/', '*', '(' };
	std::map<std::string, Operation*> operation_list = {
		{"+", new Addition()},
		{"-", new Subtraction()},
		{"*", new Multiplication()},
		{"/", new Division()}
	};

	HINSTANCE hLib;
	bool negative_num{ true };

public:
	Calculator() = default;
	~Calculator() {
		for (auto item : operation_list) {
			delete item.second;
		}

		FreeLibrary(hLib);
	}
	void loadLibraries() {

	}

	bool loadDLL();
	void reset();
	bool read(char c);
	double calculate();
	void calculateOneStep();
};

