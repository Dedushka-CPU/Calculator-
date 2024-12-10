#include <iostream>
#include "calc.h"

using std::cin;
using std::cout;
using std::string;1

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
            cout << "Ошибка: некорректное выражение. Убедитесь, что операторы и скобки расставлены правильно.\n";
            continue;
        }

        try {
            double result = CalculateBrackets(str);
            cout << "Результат: " << result << "\n";
        } catch (const std::exception& e) {
            cout << e.what() << "\n";
        }
    }

    return 0;
}
