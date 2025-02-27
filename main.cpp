#include <iostream>
#include "calculator_h.h"

using std::cin;
using std::cout;
using std::string;

int main() {
    cout << "========================\n";
    cout << "    Calculator 2.1     \n";
    cout << "========================\n";
    cout << "Напишите выражение для расчёта или 'exit' для выхода.\nВЫражения вводить без пробелов!!!\n\n";

    while (true) {
        cout << "Введите выражение: ";
        string str;
        std::getline(cin, str);
        
        if (str == "exit") {
            cout << "Выход из программы. До свидания!\n";
            break;
        }
        if (str.empty()) {
            cout << "Ошибка: пустой ввод. Попробуйте снова.\n";
            continue;
        }
        if (!isExpressionValid(str)) {
            cout << "Error 404!!!!!!!!!\n";
            continue;
        }else{
            cout<<"It's mathematical exspression\n";
            try {
                double result = CalculateBrackets(str);
                cout << "Результат: " << result << "\n";
            } catch (const std::exception& e) {
                cout << e.what() << "\n";
            }
        }
    }

    return 0;
}
