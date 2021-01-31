#include <iostream>
#include <string>

bool isCorrect(std::string str) {
  bool dot = false;
  for (int i = 0; i < str.length(); ++i) {
    if (i == 0 && str[i] == '-') {
      continue;
    } else if (!dot && str[i] == '.') {
      dot = true;
    } else if (str[i] < '0' || str[i] > '9') {
      std::cerr << "Wrong input! Try again." << std::endl;
      return false;
    }
  }
  return true;
}

int main() {
  std::string intPart, fracPart, tmp;

  do {
    std::cout << "Input integer and fractional part: ";
    std::cin >> intPart >> fracPart;
    tmp = intPart + '.' + fracPart;
  } while (!isCorrect(tmp));

  double result = std::stod(tmp);
  std::cout << "The result is: " << result << std::endl;
}

//Сшиватель дробных чисел
//
//Что нужно сделать
//
//Надо написать небольшую программу.Из целой и дробной частей числа, которые в
//отдельности вводит пользователь надо составить новое число с плавающей
//точкой(типа double) и вывести это число обратно в консоль, для проверки.Целая
//часть - это та, часть числа, которая находится до точки(запятой), дробная -
//после.