#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, int> registry;

  std::string request;

  while (true) {
    std::cout << "Enter your request: ";
    std::cin >> request;

    if (request == "Next" || request == "next") {
      break;
    } else if (!registry.contains(request)) {
      registry.insert(std::make_pair(request, 1));
    } else {
      ++registry[request];
    }
  }

  std::map<std::string, int>::iterator it = registry.begin();

  while (it != registry.end()) {
    if (request == "Next" || request == "next") {
      std::cout << it->first << std::endl;
      --it->second;

      if (it->second == 0) {
        ++it;
      }
    }

    if (it != registry.end()) {
      std::cout << "Enter your request: ";
      std::cin >> request;
    }
  }
}

//Задание 2. Регистратура
//
//
//Что нужно сделать
//
//Напишите программу «Регистратура».
//
//На вход программе приходят строки с фамилиями или строка Next.Пришедшие люди
//становятся в очередь, а по запросу Next
// необходимо вызвать в регистратуру человека с фамилией, идущей первой в
// лексикографическом порядке(по алфавиту), и вывести его фамилию на
// экран.Фамилии пациентов могут повторяться.
//
//Каждый запрос(на добавление и вывод) должен работать за O(logn).
//
//
//
//Пример:
//
//← Sidorov
//
//← Ivanov
//
//← Ivanov
//
//← Petrov
//
//← Next
//
//→ Ivanov
//
//← Next
//
//→ Ivanov
//
//← Next
//
//→ Petrov
//
//
//
//Чек - лист для проверки задачи
//
//Программа корректно выводит фамилии в лексикографическом порядке.
//Программа использует только заголовочные файлы <iostream>, <string>, <map>.