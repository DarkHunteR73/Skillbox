#include <conio.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

bool checkDate(std::string date);

int main() {
  std::ofstream payroll(".\\payroll.txt", std::ios::app);

  while (true) {
    std::string firstName, lastName, date;
    int salary;

    while (true) {
      std::string userInput;
      std::cout << "Input entry: Name, Date DD.MM.YYYY, Salary" << std::endl;
      std::getline(std::cin, userInput);
      std::istringstream entry(userInput);

      entry >> firstName >> lastName >> date >> salary;

      if (checkDate(date)) break;

      std::cerr << "Wrong date. Please try again." << std::endl;
    }

    payroll << firstName << ' ' << lastName << ' ' << date << ' ' << salary
            << std::endl;

    std::cout << "\nDo you want to continue? (y/n)" << std::endl;

    char ch = ' ';
    while (ch != 'y' && ch != 'n') {
      ch = _getch();

      if (ch == 'n') {
        std::cout << "The program is finished. Exiting..." << std::endl;
        payroll.close();
        return EXIT_SUCCESS;
      }
    }
  }
}

bool checkDate(std::string date) {
  int day = std::stoi(date.substr(0, 2));
  int month = std::stoi(date.substr(3, 2));
  int year = std::stoi(date.substr(6));
  bool leap = (year % 4 == 0 && year % 100 != 0 ^ year % 400 == 0);

  if (day < 1 || month < 1 || month > 12 || year < 1970 || year > 2199)
    return false;
  else if (month == 2 && day > (leap ? 29 : 28))
    return false;
  else if ((month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12) &&
           day > 31)
    return false;
  else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    return false;

  return true;
}

/*
Задание 1. Реализация записи в ведомость учёта


Что нужно сделать

В одном из прошлых заданий мы уже создавали программу чтения и анализа ведомости
выплат. Теперь требуется создать простую программу записи в эту ведомость.

Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных
средств, далее располагается дата выдачи в формате ДД.ММ.ГГГГ. Завершает запись
сумма выплаты в рублях. Данные разделяются между собой пробелами. В конце каждой
записи должен быть расположен перевод строки.

При старте программы пользователь последовательно вводит данные для новой
записи, которые записываются затем в файл в текстовом режиме. Программа должна
добавлять новые записи в конец файла, не удаляя его текущее содержимое.


Советы и рекомендации

Введённые данные рекомендуется хотя бы минимально валидировать перед их записью.

Для валидации даты в указанном формате можно использовать функции std::stoi и
std::subtr с корректно указанным диапазоном символов в дате. К примеру, вызов
std::stoi(date.substr(3, 2)) вычленит из строковой даты целочисленный месяц для
последующего анализа.


Что оценивается

Корректность работы программы. Программа должна дозаписывать данные в конец
существующего списка.
*/