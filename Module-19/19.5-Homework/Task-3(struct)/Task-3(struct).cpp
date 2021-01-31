#include <fstream>
#include <iostream>
#include <vector>

struct Entry {
  Entry(std::string& _fN, std::string& _lN, int _s, std::string& _d) {
    name = _fN + ' ' + _lN;
    salary = _s;
    date = _d;
  };

  std::string name;
  int salary;
  std::string date;
};

int main() {
  std::ifstream payroll;

  payroll.open(".\\payroll.txt");

  if (!payroll.is_open()) {
    std::cerr << "File open error!" << std::endl;
  } else {
    std::vector<Entry> database;

    std::string firstName, lastName, date;
    int salary, totalAmount = 0, topSalary = 0, topSalaryEntry = 0;

    for (size_t i = 0; !payroll.eof(); ++i) {
      payroll >> firstName >> lastName >> salary >> date;
      totalAmount += salary;
      database.push_back(Entry(firstName, lastName, salary, date));

      if (salary > topSalary) {
        topSalary = salary;
        topSalaryEntry = i;
      }
    }

    std::cout << "Total amount: " << totalAmount << std::endl;
    std::cout << "Top salary is: " << database[topSalaryEntry].name << '\t'
              << database[topSalaryEntry].salary << std::endl;
  }
}