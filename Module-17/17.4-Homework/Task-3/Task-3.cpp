#include <iostream>

bool substr(const char* str, const char* substr) {
  for (int i = 0; *(str + i) != '\0'; ++i) {
    if (*(str + i) == *substr) {
      for (int j = 1;; ++j) {
        if (*(str + i + j) == '\0' && *(substr + j) != '\0') {
          return false;
        } else if (*(substr + j) == '\0') {
          return true;
        } else if (*(str + i + j) != *(substr + j)) {
          break;
        }
      }
    }
  }
  return false;
}

int main() {
  const char* a = "Hello world";
  //                  lo    ldoo
  const char* b = "wor";
  const char* c = "banana";

  std::cout << (substr(a, b) ? "true" : "false") << ' '
            << (substr(a, c) ? "true" : "false") << std::endl;
}

//Задача 3.
//
//Что нужно сделать :
//
//Написать функцию, которая принимаем указатель на char, по которому лежит
//строка.
//
//Функция должна возвращать true, если вторая строка является подстрокой первой.
//
//
//Пример :
//
// char* a = “Hello world”;
//
// char* b = “wor”;
//
// char* c = “banana”;
//
// std::cout << substr(a, b) << “ “ << substr(a, c);
//
//// true false
//
//
//Чек - лист для проверки задачи
//
//Функция принимает корректные типы данных, тип возвращаемого значения-- bool
//Функция не использует библиотек кроме <iostream>
//Функция корректно определяет, является ли вторая строка подстрокой первой
