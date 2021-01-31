#include <iostream>

void fillArray(int *arr, int size) {
  for (int i = 0; i < size; ++i) {
    *(arr + i) = std::rand() % 100;
  }
}

void printArray(int *arr, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << *(arr + i) << ' ';
  }
  std::cout << std::endl;
}

void reverseArray(int *arr, int size) {
  for (int i = 0; i < size / 2; ++i) {
    int tmp = *(arr + i);
    *(arr + i) = *(arr + size - i - 1);
    *(arr + size - i - 1) = tmp;
  }
}

int main() {
  const int SIZE = 10;

  int arr[SIZE];
  fillArray(arr, SIZE);

  printArray(arr, SIZE);

  reverseArray(arr, SIZE);

  printArray(arr, SIZE);
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