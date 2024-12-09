#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cctype>
#include <stack>

using std::cin;
using std::cout;
using std::string;

bool isExpressionValid(const string& str) {
    bool lastOperator = false;
    int openBrackets = 0;

    for (char s : str) {
        if (isdigit(s) || s == '.') {
            lastOperator = false;
        } else if (s == '+' || s == '-' || s == '*' || s == '/' || s == '^') {
            if (lastOperator) return false; 
            lastOperator = true;
        } else if (s == '(') {
            ++openBrackets;
            lastOperator = true;
        } else if (s == ')') {
            if (openBrackets == 0 || lastOperator){
                return false;
            } 
            --openBrackets;
            lastOperator = false;
        } else if (!isspace(s)) {
            return false; 
        }
    }

    return openBrackets == 0 && !lastOperator; 
}

double Calculate(const string& str) {
    string temp = "";
    std::vector<double> numbers;
    std::vector<char> operations;

    for (char s : str) {
        if (isdigit(s) || s == '.') {
            temp += s;
        } else if (s == '+' || s == '-' || s == '*' || s == '/' || s == '^') {
            if (!temp.empty()) {
                numbers.push_back(std::stod(temp));
                temp = "";
            }
            operations.push_back(s);
        }
    }
    if (!temp.empty()) {
        numbers.push_back(std::stod(temp));
    }

    for (size_t i = 0; i < operations.size(); ++i) {
        if (operations[i] == '*' || operations[i] == '/' || operations[i] == '^') {
            double result;
            if (operations[i] == '*') {
                result = numbers[i] * numbers[i + 1];
            } else if (operations[i] == '/') {
                if (numbers[i + 1] == 0) {
                    throw std::runtime_error("Error: Division by zero!");
                }
                result = numbers[i] / numbers[i + 1];
            } else if (operations[i] == '^') {
                result = pow(numbers[i], numbers[i + 1]);
            }
            numbers[i] = result;
            numbers.erase(numbers.begin() + i + 1);
            operations.erase(operations.begin() + i);
            --i;
        }
    }

    double result = numbers[0];
    for (size_t i = 0; i < operations.size(); ++i) {
        if (operations[i] == '+') {
            result += numbers[i + 1];
        } else if (operations[i] == '-') {
            result -= numbers[i + 1];
        }
    }

    return result;
}

double CalculateBrackets(string str) {
    std::stack<size_t> brackets; 

    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            brackets.push(i);
        } else if (str[i] == ')') {
            if (brackets.empty()) throw std::runtime_error("Error: Mismatched brackets!");

            size_t openIndex = brackets.top();
            brackets.pop();

            string subExpression = str.substr(openIndex + 1, i - openIndex - 1);
            double result = Calculate(subExpression);

            str.replace(openIndex, i - openIndex + 1, std::to_string(result));
            i = openIndex + std::to_string(result).size() - 1; // Обновляем индекс
        }
    }

    return Calculate(str);
}

int main() {
    cout << "========================\n";
    cout << "    Calculator 2.0     \n";
    cout << "========================\n";
    cout << "Напишите выражение для расчёта или 'exit' для выхода.\n\n";

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
