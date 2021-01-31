#include <iostream>
#include <sstream>

double calculate(std::string str) {
  std::istringstream tmp(str);
  char operation;
  double num1, num2;

  tmp >> num1 >> operation >> num2;

  if (operation == '+')
    return num1 + num2;

  else if (operation == '-')
    return num1 - num2;

  else if (operation == '*')
    return num1 * num2;

  else if (operation == '/')
    return num1 / num2;
}

int main() {
  std::string user_input;

  std::cout << "Input expression: ";
  std::cin >> user_input;

  std::cout << "Result: " << calculate(user_input) << std::endl;
}

//Калькулятор
//
//Что нужно сделать
//
//Требуется создать небольшую программу для вычисления простых действий с
//числами. При запуске программа ожидает пользовательского ввода во временную
//переменную строку.После ввода строки, она распарсивается на отдельные члены.
//Строка записывается в форме “<число - 1><действие><число - 2>”(без
//пробелов).Оба числа - это значения с плавающей точкой, повышенной
//точности(double). Действие может быть одним из : +, -, / , * .Результат
//действия выводится в стандартный вывод cout.