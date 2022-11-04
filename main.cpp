#include "Calculator.h"

using namespace std;



int main(){
    setlocale(LC_ALL, "RU");
    bool isExit{ false };
    Calculator calc;
    calc.loadDLL();

    cout << "   Перед ваши калькулятор, запишите выражение: \n";
    while (!isExit) {
        char sym{};
        sym = cin.peek();
        
        while (sym != '\n') {
            calc.read(sym);
            sym = cin.peek();
        }
        
        cout << "Ответ: " << calc.calculate() << endl;
        cout << "   Продолжить вычисления [y/n]: ";
        char ans{};
        cin >> ans;
        if (ans != 'y') {
            isExit = true;
        }
        else {
            calc.reset();
            sym = '\0';
            cin.ignore();
        }
    }

    return 0;
}

