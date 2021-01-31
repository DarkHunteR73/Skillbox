#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  // map для поиска по номерам телефонов
  std::map<std::string, std::string> numberToLastNameMap;

  // map для поиска по фамилии
  std::map<std::string, std::vector<std::string>> lastNameToNumberMap;

  while (true) {
    std::cout << "Enter your request: ";
    std::string request;
    std::getline(std::cin, request);

    if (request == "exit") {
      std::exit(EXIT_SUCCESS);
    }

    if (request[0] >= '0' && request[0] <= '9' &&
        request[request.length() - 1] >= 'a' &&
        request[request.length() - 1] <= 'z') {
      int pos = request.find(' ');
      if (pos > 0) {
        std::string number = request.substr(0, pos);
        std::string lastName = request.substr(pos + 1, request.length() - pos);

        if (numberToLastNameMap.contains(number)) {
          numberToLastNameMap[number] = lastName;
        } else {
          numberToLastNameMap.insert(std::make_pair(number, lastName));
        }

        if (lastNameToNumberMap.contains(lastName)) {
          std::vector<std::string>& numVec = lastNameToNumberMap[lastName];
          numVec.push_back(number);
        } else {
          std::pair<std::string, std::vector<std::string>> newEntry{lastName,
                                                                    {number}};
          lastNameToNumberMap.insert(newEntry);
        }
      } else {
        std::cout << "Error! <Space> not found" << std::endl;
      }
    } else if (request[0] >= '0' && request[0] <= '9' &&
               request[request.length() - 1] >= '0' &&
               request[request.length() - 1] <= '9') {
      std::cout << "Search result for the query \"" << request << "\": "
                << (numberToLastNameMap.contains(request)
                        ? numberToLastNameMap[request]
                        : "Nothing found")
                << std::endl;
    } else if ((request[0] >= 'A' && request[0] <= 'Z' ||
                request[0] >= 'a' && request[0] <= 'z') &&
               request[request.length() - 1] >= 'a' &&
               request[request.length() - 1] <= 'z') {
      std::cout << "Search results for the query \"" << request << "\": ";

      if (lastNameToNumberMap.contains(request)) {
        std::vector<std::string>& entry = lastNameToNumberMap[request];
        if (entry.size() > 1) std::cout << std::endl;

        for (int i = 0; i < entry.size(); ++i) {
          std::cout << entry[i] << std::endl;
        }
      } else {
        std::cout << "Nothing found" << std::endl;
      }
    } else {
      std::cout << "Unknown request! Please try again" << std::endl;
    }
  }
}

//Задание 1. Телефонный справочник
//
//
//Что нужно сделать
//
//Напишите программу «Телефонный справочник».
//
//На вход программе поступают запросы трёх типов :
//
// 69 - 70 - 30 Ivanov — добавить телефон и фамилию абонента в справочник
//
// 69 - 70 - 30 — узнать фамилию абонента по номеру телефона
//
// Ivanov — узнать телефон абонента по фамилии
//
//
//Необходимо выводить в консоль ответ на запросы 2 и 3. Обратите внимание, что
//абоненты по разным номерам могут иметь одинаковые фамилии.В таком случае на
//запрос 3 необходимо выдать все номера через пробелы.
//
//Операции запросов должны работать за O(logn) или O(logn × количество номеров с
//этой фамилией).
//
//
//Чек - лист для проверки задачи
//
//Программа корректно выводит фамилии и списки номеров.
//Программа использует только заголовочные файлы <iostream>, <string>, <map> и,
//возможно, вектор.
