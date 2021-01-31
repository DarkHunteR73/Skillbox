#include <conio.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

struct InputForm {
  std::string firstName;
  std::string lastName;
  std::string date;
  int salary = 0;
};

bool checkDate(std::string date);

int main() {
  std::cout
      << "Select operation ('a' to add new entry, 'l' to list all entries):"
      << std::endl;
  char operation = ' ';
  while (operation != 'a' && operation != 'l') {
    operation = _getch();

    if (operation == 'a') {
      std::ofstream outPayroll(".\\payroll.txt", std::ios::app);
      InputForm entry;

      while (true) {
        std::cout << "Input entry: Name, Date DD.MM.YYYY, Salary" << std::endl;
        std::string userInput;
        std::getline(std::cin, userInput);

        std::istringstream inEntry(userInput);
        inEntry >> entry.firstName >> entry.lastName >> entry.date >>
            entry.salary;

        if (checkDate(entry.date)) break;

        std::cerr << "Wrong date. Please try again." << std::endl;
      }

      outPayroll << entry.firstName << ' ' << entry.lastName << ' '
                 << entry.date << ' ' << entry.salary << std::endl;
      outPayroll.close();
    } else if (operation == 'l') {
      std::ifstream inPayroll(".\\payroll.txt");

      if (!inPayroll.is_open()) {
        std::cerr << "Error! File not exist." << std::endl;
        return EXIT_FAILURE;
      } else {
        while (!inPayroll.eof()) {
          InputForm entry;

          inPayroll >> entry.firstName >> entry.lastName >> entry.date >>
              entry.salary;

          if (entry.firstName.empty()) continue;

          std::cout << entry.firstName << ' ' << entry.lastName << ' '
                    << entry.date << ' ' << entry.salary << std::endl;
        }
      }

      inPayroll.close();
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
Задание 1. Реализация ведомости учёта


Что нужно сделать

Вы уже создавали программу чтения и записи ведомости. Теперь её надо будет
обобщить и дополнить использованием структур.

Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных
средств, далее — дата выдачи в формате ДД.ММ.ГГГГ., затем — сумма выплаты в
рублях. Данные разделяются между собой пробелами. В конце каждой записи должен
быть перевод строки.

Структура данных записи должна соответствовать указанному формату.

При старте программы пользователь указывает команду, которую следует
осуществить: list или add. Команда read осуществляет чтение из файла ведомости
как и прежде, только уже в структуры данных и отображает их на экране.

Команда add добавляет новую запись в конец ведомости.


Советы и рекомендации

Чтобы определить конец файла, используйте функцию file.eof() как и прежде. Из-за
завершающего переноса строки, также стоит проверить и имя. Если оно было считает
пустым, то можно считать, что файл закончился.


Что оценивается

Корректность работы программы. Программа должна всегда использовать структуры и
все операции проводить через них.
*/