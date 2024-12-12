# Калькулятор выражений

## Описание
Этот проект представляет собой калькулятор, который поддерживает вычисление математических выражений с использованием стандартных операторов, таких как сложение, вычитание, умножение, деление, возведение в степень, а также обработку скобок. Программа проверяет корректность введённого выражения и сообщает об ошибках, таких как неправильное использование точек или некорректные символы.

## Функционал
- **Поддерживаемые операции**: `+`, `-`, `*`, `/`, `^`.
- **Обработка скобок**: Поддержка вложенных скобок для сложных выражений.
- **Проверка корректности**: Включает валидацию выражений, включая использование точек в десятичных числах.
- **Обработка ошибок**: Сообщает о некорректных вводах, таких как `1.2.3` или отсутствие закрывающей скобки.

## Структура проекта
- `calc.h` — заголовочный файл, содержащий объявления функций.
- `calc.cpp` — реализация функций для вычислений и проверки выражений.
- `main.cpp` — точка входа в программу (если требуется).
- `tests.cpp` — тесты, написанные с использованием библиотеки Doctest.

## Использование
1. Включите файл `calc.h` в ваш проект.
2. Используйте функцию `CalculateBrackets`, чтобы вычислить выражение.
3. Выражение должно быть передано в виде строки.

### Пример
```cpp
#include "calc.h"
#include <iostream>

int main() {
    try {
        std::string expression = "(2+3)*4";
        double result = CalculateBrackets(expression);
        std::cout << "Результат: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
```

### Примеры выражений
- Корректные:
  - `1+2`
  - `(3+5)*2`
  - `2.5*4.2`
  - `10/(5-3)`
  - `2^(1/2)`
- Некорректные:
  - `1.2.3` — более одной точки в числе.
  - `(2+3` — отсутствует закрывающая скобка.
  - `2+*3` — два оператора подряд.

## Тестирование
Тесты написаны с использованием библиотеки Doctest. Для их выполнения используйте команду компиляции:
```bash
g++ -std=c++17 -o tests tests.cpp calc.cpp -ldoctest
./tests
```
Тесты проверяют корректность выполнения операций, обработку скобок и случаев с ошибками.

## Обработка ошибок
Если выражение некорректно, программа выбросит исключение `std::runtime_error` с описанием ошибки. Например:
- `Error: Division by zero!`
- `Error: Invalid expression.`



