#include <iostream>

void FillArray(int* arr, int size) {
  for (int i = 0; i < size; ++i) {
    *(arr + i) = std::rand() % 100;
  }
}

void PrintArray(int* arr, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << *(arr + i) << ' ';
  }
  std::cout << std::endl;
}

int* ReverseArray(int* arr, int size) {
  int* revArr = new int[size];

  for (int i = 0; i < size; ++i) {
    *(revArr + i) = *(arr + size - i - 1);
  }

  return revArr;
}

int main() {
  const int SIZE = 10;

  int arr[SIZE];
  FillArray(arr, SIZE);

  int* reversedArr = ReverseArray(arr, SIZE);

  PrintArray(arr, SIZE);
  PrintArray(reversedArr, SIZE);

  delete[] reversedArr;
}

//Задача 2.
//
//Что нужно сделать :
//
//Написать функцию, которая принимает указатель на тип int, по которому
//размещены 10 переменных типа int.Функция должна вернуть другой указатель на
//int, по которому лежат те же элементы, но в обратном порядке
//
//Чек - лист для проверки задачи
//
//Функция принимает корректные типы данных, тип возвращаемого значения--  int*
//Функция не использует библиотек кроме <iostream>
//По новому указателю лежат переменные в обратном порядке