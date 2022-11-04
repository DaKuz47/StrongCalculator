#include "Calculator.h"

typedef Operation* (*OperPtr) ();

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
	if(one_symbol_operations.find(c) != one_symbol_operations.end()) {
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

void Calculator::reset() {
	negative_num = true;
	stack_numbers.erase();
	stack_opr.erase();
}

bool Calculator::loadDLL() {
	//get DLL filenames
	std::vector<std::string>dll_name_list;
	std::string str = ".\\plugins\\*.dll";
	WIN32_FIND_DATAA FindFileData;
	HANDLE hf;
	hf = FindFirstFileA(str.c_str(), &FindFileData);
	if (hf != INVALID_HANDLE_VALUE)
	{
		do
		{
			dll_name_list.push_back("./plugins/" + std::string(FindFileData.cFileName));
		} while (FindNextFileA(hf, &FindFileData) != 0);
		FindClose(hf);
	}

	HINSTANCE hLib;
	OperPtr f;

	//Loading dll operations into our calculator
	for (std::string name : dll_name_list) {
		hLib = LoadLibraryA(name.c_str());
		if (hLib == NULL) {
			std::cerr << "Не удалось подключить DLL\n";
			return false;
		}

		f = (OperPtr)GetProcAddress(hLib, "getOperationClass");
		if (!f) {
			std::cerr << "Не удалось найти функтсионал в загруженной DLL\n";
			return false;
		}

		Operation* o = f();
		if (o->getName() == std::string(1, o->getFirstOfName())) {
			one_symbol_operations.insert(o->getFirstOfName());
		}

		operation_list[o->getName()] = o;
	}
	return true;
}