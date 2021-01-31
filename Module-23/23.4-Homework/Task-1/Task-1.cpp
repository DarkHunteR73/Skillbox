#include <iostream>

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

int main() {
  int day;
  std::cin >> day;

  switch (day) {
    case MONDAY:
      std::cout << "Monday" << std::endl;
      break;
    case TUESDAY:
      std::cout << "Tuesday" << std::endl;
      break;
    case WEDNESDAY:
      std::cout << "Wednesday" << std::endl;
      break;
    case THURSDAY:
      std::cout << "Thursday" << std::endl;
      break;
    case FRIDAY:
      std::cout << "Friday" << std::endl;
      break;
    case SATURDAY:
      std::cout << "Saturday" << std::endl;
      break;
    case SUNDAY:
      std::cout << "Sunday" << std::endl;
      break;
    default:
      std::cout << "Unknown" << std::endl;
      break;
  }
}

//Задание 1. Реализация продвинутый ввод и вывод дней недели
//
//
//Что нужно сделать
//
//Используя макросы, реализуйте небольшую программу по вводу дня недели и выводу
//этого дня недели в текстовом виде в консоль.
//
//В начале программы пользователь вводит день недели в виде его порядкового
//номера.В результате в консоли появляется буквенное отображение этого дня
//недели.
//
//В этом упражнении запрещается использовать классические переменные, кроме как
//для хранения ввода пользователя. Использовать строковые литералы напрямую тоже
//нельзя.Всё должно быть реализовано исключительно на макросах.
//
//
//Советы и рекомендации
//
//Конкатенация двух фрагментов может породить токен, который в свою очередь
//является именем макроса, и этот макрос тоже раскроется. Используйте данное
//свойство для перевода константы дня недели в строковый литерал.
//
//Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью
//“Shift - Shift->Preprocess current TU”.
//
//
//Что оценивается
//
//Корректность работы программы.Модульность и элегантность решения с помощью
//макросов.