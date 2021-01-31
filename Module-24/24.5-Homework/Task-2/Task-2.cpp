#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Entry {
  std::string name;
  std::tm birthday{};
  int age = 0;
};

Entry getEntry(const std::string& _name, const std::tm& _localDate) {
  Entry newEntry;

  newEntry.name = _name;
  std::cout << "Enter date (YYYY/MM/DD): ";
  std::cin >> std::get_time(&newEntry.birthday, "%Y/%m/%d");
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  int tmpYear = newEntry.birthday.tm_year;
  newEntry.birthday.tm_year = _localDate.tm_year;
  newEntry.birthday.tm_isdst = 0;

  std::time_t birthdayPosix = std::mktime(&newEntry.birthday);
  newEntry.birthday = *std::localtime(&birthdayPosix);

  newEntry.age = newEntry.birthday.tm_year - tmpYear;

  return newEntry;
}

std::pair<int, std::vector<Entry>> getPair(const Entry& _entry) {
  std::pair<int, std::vector<Entry>> newPair;
  std::vector<Entry>& newEntry = newPair.second;

  newEntry.push_back(_entry);
  newPair.first = newEntry.back().birthday.tm_yday;

  return newPair;
}

int main() {
  std::time_t currentTime = std::time(nullptr);
  std::tm currentDate = *std::localtime(&currentTime);
  currentDate.tm_hour = 0;
  currentDate.tm_min = 0;
  currentDate.tm_sec = 0;

  std::map<int, std::vector<Entry>> calendarMap;

  while (true) {
    std::cout << "Enter name: ";
    std::string userInput;
    std::getline(std::cin, userInput);

    if (userInput != "end") {
      Entry entry = getEntry(userInput, currentDate);
      int yDay = entry.birthday.tm_yday;

      if (calendarMap.contains(yDay)) {
        calendarMap[yDay].push_back(entry);
      } else {
        calendarMap.insert(getPair(entry));
      }
    } else {
      break;
    }
  }

  int currentYDay = currentDate.tm_yday;

  std::map<int, std::vector<Entry>>::iterator it =
      calendarMap.upper_bound(currentYDay - 1);

  if (it != calendarMap.end()) {
    std::vector<Entry>& result = it->second;

    if (result.back().birthday.tm_yday == currentDate.tm_yday) {
      std::cout << "Birthday is celebrated today:" << std::endl;
    } else {
      std::cout << "The nearest birthday will be "
                << std::put_time(&result.back().birthday, "%m/%d") << std::endl;
    }

    for (int i = 0; i < result.size(); ++i) {
      std::cout << result[i].name << ", " << result[i].age << " year(s)"
                << std::endl;
    }
  } else {
    std::cout << "There will be no more birthdays in this year" << std::endl;
  }
}

//Задание 2. Реализация программы напоминания о днях рождения
//
//    Что нужно сделать
//
//        Реализуйте простую программу по вычислению ближайшего дня рождения.
//
//    В начале программы пользователь последовательно вводит данные о днях
//        рождения своих друзей : вводит имя друга и саму дату рождения
//        полностью,
//    включая месяц и год,
//    в формате год / месяц /
//        день.Сигналом окончания ввода дней рождения является “end” введённое в
//            качестве имени.
//
//        После этого программа вычисляет ближайший день рождения по отношению к
//            текущему времени и выводит его на экран вместе с именем в удобном,
//    локальном формате - месяц / день.Если день рождения уже был в этом году,
//    данные о пользователе пропускаются.Если у кого -
//        то из друзей день рождения сегодня,
//    то в консоль выводится специальное сообщение об этом.Учтите,
//    что таких сообщений может быть несколько,
//    ведь сразу несколько людей могут иметь дни рождения в один
//        день.
//
//    Советы и рекомендации
//
//        Для подсчёта ближайшего дня используйте данные из структуры даты
//        std::tm
//            .
//
//    Что оценивается
//
//        Корректность работы программы.
