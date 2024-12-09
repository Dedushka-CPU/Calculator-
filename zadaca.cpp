#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cctype>

using std::cin;
using std::cout;

bool isValidExpression(const std::string& str) {
    for (char s : str) {
        if (!(isdigit(s) || s == '.' || s == '+' || s == '-' || s == '*' || s == '/' || s == '^')) {
            return false;
        }
    }
    return true;
}

int main(){
    std::string str;
    cout << "Hello! Calculator 1.0\nWrite your expression: ";
    std::getline(cin, str);
    if (str.empty()) {
        cout << "Error: Empty input\n";
        return 1;
    }
    if (!isValidExpression(str)) {
        cout << "Error: Write true symbols.\n";
        return 1;
    }
    std::string temp = "";
    std::vector<double> numbers;
    std::vector<char> operations;

    for(auto s : str) {
        if (isdigit(s) || s == '.') {
            temp += s;
        } else if (s == '+' || s == '-' || s == '*' || s == '/' || s=='^') {
            if (!temp.empty()) {
                try {
                    numbers.push_back(std::stod(temp));
                } catch (const std::invalid_argument&) {
                    cout << "Error: Invalid number format.\n";
                    return 1;
                }
                temp = "";
            }
            operations.push_back(s);
        }
    }
    if (!temp.empty()) {
        try {
            numbers.push_back(std::stod(temp));
        } catch (const std::invalid_argument&) {
            cout << "Error: Invalid number format.\n";
            return 1;
        }
    }
    for (size_t i = 0; i < operations.size(); ++i) {
        if (operations[i] == '*' || operations[i] == '/' || operations[i] == '^') {
            double result;
            if (operations[i] == '*') {
                result = numbers[i] * numbers[i + 1];
            } else if (operations[i] == '/') {
                if (numbers[i + 1] == 0) {
                    cout << "Error: Division by zero!\n";
                    return 1;
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

    cout << "Result: " << result << "\n";
    return 0;
}
