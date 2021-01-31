#include <iostream>

void Swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int num1 = 10, num2 = 50;
  std::cout << "num1 = " << num1 << std::endl;
  std::cout << "num2 = " << num2 << std::endl;

  std::cout << "\nSwap this...\n" << std::endl;
  Swap(&num1, &num2);

  std::cout << "num1 = " << num1 << std::endl;
  std::cout << "num2 = " << num2 << std::endl;
}

//Задача 1.
//
//Что нужно сделать :
//
//Написать функцию, принимающую два указателя на int и меняет местами содержимое
//данных указателей.
//
//Пример :
//
//    int a = 10;
//
// int b = 20;
//
// swap(&a, &b);
//
// std::cout << a << “ “ << b;
//
//// 20 10
//
//
//Чек - лист для проверки задачи
//
//Функция принимает корректные типы данных, тип возвращаемого значения-- void
//Функция не использует библиотек кроме <iostream>
//Функция меняет значения по указателям
