#include "Calculator.h"

bool Calculator::read(char c) {
	//space checker
	if (c == ' ') {
		std::cin.ignore();
		return true;
	}

	//negative number can place only in start of expretion or in start of ( )
	if (negative_num && c == '-') {
		double num;
		std::cin >> num;
		stack_numbers.push(num);
		return true;
	}
	else if (negative_num) {
		negative_num = false;
	}

	if (c == ')') {
		//calculate all operations in ( )
		while (stack_opr.top() != "(") {
			calculateOneStep();
		}
		stack_opr.pop();
		std::cin.ignore();
		return true;
	}
	//number chcker
	if (c >= '0' && c <= '9') {
		double num;
		std::cin >> num;
		stack_numbers.push(num);
		return true;
	}
	//operation checker
	std::string operation{};
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(') {
		if (c == '(') {
			negative_num = true;
		}
		operation = std::string(1, c);
		std::cin.ignore();
	}
	else {
		char str[4]{};
		std::cin.get(str, 4);
		operation = std::string(str);
	}

	//If current prior <= prev prior, then start prev operation right now
	while (!stack_opr.empty() && stack_opr.top() != "(" && operation != "(") {
		if (operation_list[operation]->getPriority() <= operation_list[stack_opr.top()]->getPriority()) {
			calculateOneStep();
		}
		else {
			break;
		}
	}

	stack_opr.push(operation);
	return true;
}

void Calculator::calculateOneStep() {
	std::string operation = stack_opr.pop();
	operation_list[operation]->calculate(stack_numbers);
}

double Calculator::calculate() {
	while (stack_numbers.getSize() > 1) {
		calculateOneStep();
	}
	return stack_numbers.pop();
}
