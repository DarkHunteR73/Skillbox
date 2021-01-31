#include <iostream>
#include <vector>

void fillArrays(std::vector<int>& vec, int arr[]) {
  for (int i = 0; i < vec.size(); ++i) {
    vec[i] = std::rand() % 100;
    arr[i] = std::rand() % 100;
  }
}

void swapVec(std::vector<int>& vec, int arr[]) {
  for (int i = 0; i < vec.size(); ++i) {
    int tmp = vec[i];
    vec[i] = arr[i];
    arr[i] = tmp;
  }
}

void print(std::vector<int>& vec, int arr[]) {
  std::cout << "Vector:\t";
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << ' ';
  }

  std::cout << "\nArray:\t";
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << std::endl;
}

int main() {
  const int SIZE = 10;
  std::vector<int> a(SIZE);
  int b[SIZE];

  fillArrays(a, b);

  print(a, b);

  std::cout << "\nNow swap this...\n" << std::endl;

  swapVec(a, b);

  print(a, b);
}

//Задача 1
//
//Что нужно сделать
//
//Напишите функцию swapvec, принимающую std::vector<int> и указатель на массив
//переменных типа int(одного размера) и обменивающую значения этих массивов.
//
//Пример:
//
// std::vector<int> a = { 1,2,3,4 };
//
// int b[] = { 2,4,6,8 };
//
// swapvec(a, b);
//
// for (int i = 0; i < 4; ++i)
//
//    std::cout << a[i];
//
// std::cout << std::endl;
//
// for (int i = 0; i < 4; ++i)
//
//    std::cout << b[i];
//
//
//Вывод:
//
// 2468
//
// 1234
//
//
//Чек - лист для проверки задачи
//
//Функция принимает корректные типы данных, тип возвращаемого значения — void.
//Функция не использует библиотек кроме <iostream> и <vector>.
//Функция меняет значения между объектами.
//Вектор передаётся по ссылке.
