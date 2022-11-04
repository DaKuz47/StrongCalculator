#pragma once
#include <string>
#include "Stack.h"

class Operation {
protected:
	int priority;
	std::string name;
public:
	Operation(std::string n = "", int p = 0) : priority{ p }, name{ n } {};
	int getPriority() const { return priority; }
	std::string getName() const { return name; }
	char getFirstOfName() const { return name[0]; }
	virtual void calculate(Stack<double, 30>& stack) = 0;
};