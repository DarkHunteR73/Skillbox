#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Task {
  bool active = true;
  std::string name;
  std::time_t beginTime;
  std::time_t endTime;
};

Task newTask() {
  Task result;
  std::cout << "Enter the task name: ";

  std::getline(std::cin, result.name);
  result.beginTime = std::time(nullptr);

  return result;
}

int main() {
  std::vector<Task> task;

  while (true) {
    std::string command;
    std::cout << "Enter command: ";
    std::cin >> command;
    std::cin.ignore(std::numeric_limits<size_t>::max(), '\n');

    if (command == "exit") {
      std::exit(EXIT_SUCCESS);
    } else if (command == "begin") {
      if (task.empty() || !task.back().active) {
        task.push_back(newTask());
      } else {
        task.back().active = false;
        task.back().endTime = std::time(nullptr);
        task.push_back(newTask());
      }
    } else if (command == "end") {
      if (!task.empty() && task.back().active) {
        task.back().active = false;
        task.back().endTime = std::time(nullptr);
      }
    } else if (command == "status") {
      if (task.empty()) {
        std::cout << "No completed or active tasks." << std::endl;
      } else {
        task.back().endTime = std::time(nullptr);

        for (int i = 0; i < task.size(); ++i) {
          double diff = std::difftime(task[i].endTime, task[i].beginTime);
          std::time_t diffTime = (std::time_t)diff;
          std::tm* buf = std::gmtime(&diffTime);

          std::cout << "Task " << i + 1 << ": " << task[i].name << " | "
                    << std::put_time(buf, "%H:%M:%S") << " | "
                    << (task[i].active ? "Active" : "Completed") << std::endl;
        }
      }
    }
  }
}

//Задание 1. Реализация программы учёта времени
//
//Что нужно сделать
//
//Используя функцию получения текущего времени std::time, реализуйте простейший
//менеджер учёта времени.
//
//Пользователь взаимодействует с программой с помощью команд :
//
//Команда begin начинает отслеживание новой задачи.После ввода этой команды
//пользователь должен ввести название задачи, над которой он планирует сейчас
//работать.Если уже была начата какая - то другая задача, предыдущая должна быть
//автоматически завершена и начата новая.
//Команда end заканчивает отслеживание текущей задачи.Если текущей начатой
//задачи нет, то команда ничего не делает. Команда status выводит на экран
//информацию о всех законченных задачах и времени, которое было на них
//потрачено. Также выводится название текущей выполняемой задачи, если таковая
//имеется. Команда exit выходит из программы.
//
//
//Советы и рекомендации
//
//Тип std::time_t принимайте за секунды и с помощью него рассчитывайте время в
//часах, которое было затрачено.
//
//
//Что оценивается
//
//Корректность работы программы.