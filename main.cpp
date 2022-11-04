#include "Calculator.h"

using namespace std;



int main(){
    setlocale(LC_ALL, "RU");
    bool isExit{ false };
    Calculator calc;
    if (!calc.loadDLL()) {
        "\nВозникла ошибка при загрузке дополнительный операций, доступны только базовые\n";
    }

    cout << "   Перед ваши калькулятор, запишите выражение: \n";
    while (!isExit) {
        char sym{};
        sym = cin.peek();
        try {
            while (sym != '\n') {
                if (!calc.read(sym)) {
                    std::cout << "\nВозникла ошибка при чтении данных\n";
                    cin.ignore(1024, '\n');
                    calc.reset();
                    break;
                }
                sym = cin.peek();
            }

            cout << "Ответ: " << calc.calculate() << endl;
        }
        catch (const char* msg) {
            std::cerr << msg << std::endl;
            cin.ignore(1024, '\n');
            calc.reset();
        }

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

