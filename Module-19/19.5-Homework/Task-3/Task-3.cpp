#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream payroll;
  payroll.open(".\\payroll.txt");

  if (payroll.is_open()) {
    int salary = 0, topSalary = 0, totalAmount = 0;
    std::string firstName, lastName, date;
    std::string topEmplyee;

    while (!payroll.eof()) {
      payroll >> firstName >> lastName >> salary >> date;
      totalAmount += salary;

      if (salary > topSalary) {
        topSalary = salary;
        topEmplyee = firstName + ' ' + lastName;
      }
    }

    std::cout << "Total amount: " << totalAmount << std::endl;
    std::cout << "Employee with the highest salary: " << topEmplyee
              << std::endl;
  } else {
    std::cerr << "Error opening file!" << std::endl;
  }
}

/*
Задание 3. Реализация программы чтения ведомости


Что нужно сделать

Реализуйте программу чтения информации из ведомости по учёту выплат. Сама
ведомость представляет собой следующую таблицу:

    имя и фамилия человека;
    количество денег, которые были выплачены лицу;
    дата выплаты в формате ДД.ММ.ГГГГ.

На основе данных из ведомости следует подсчитать общее количество выплаченных
средств и определить человека с максимальной суммой выплат.


Пример данных ведомости

Tom Hanks 35500 10.11.2020

Rebecca Williams 85000 1.1.2021

Sally Field 15600 15.8.2021

Michael Humphreys 29400 23.5.2020

Harold Herthum 74300 9.6.2019

George Kelly 45000 12.3.2018

Bob Penny 12500 13.5.2020

John Randall 23400 2.10.2020

Sam Anderson 6500 15.7.2020

Margo Moorer 12350 24.2.2019


Что оценивается

Корректное отображение общей суммы выплат и самого крупного получателя денежных
средств.



*/