﻿#include <fstream>
#include <iostream>

int main() {
  const int SIZE = 100;
  std::string pathToFile;
  std::cout << "Path to file: ";
  std::cin >> pathToFile;

  std::ifstream text;
  text.open(pathToFile, std::ios::binary);

  if (text.is_open()) {
    system("cls");
    char buffer[SIZE];

    while (!text.eof()) {
      text.read(buffer, sizeof(buffer) - 1);
      buffer[text.gcount()] = '\0';

      std::cout << buffer;
    }

    std::cout << std::endl;
    text.close();
  } else {
    std::cerr << "Error! Wrong path or file not exist." << std::endl;
  }
}

/*
Задание 2. Разработка просмотрщика текстовых файлов


Что нужно сделать

Разработайте простейший просмотрщик текстовых файлов. В начале программы
пользователь вводит путь к текстовому файлу, который требуется открыть и
просмотреть. Внутренности файла необходимо вывести в стандартный вывод.
Программа должна работать для любых текстовых файлов в формате TXT, но вы можете
создать и свой отдельный файл для теста. Главное, чтобы файл был англоязычным,
дабы избежать проблем с кодировками.


Советы и рекомендации

    Для проверки того, был ли на самом деле открыт файл, используйте метод
is_open. Он вернёт true, если файл был благополучно открыт, и false, если что-то
пошло не так, к примеру, если путь к файлу невалидный. Файл надо считывать
постепенно, отдельными фрагментами, ведь он может быть весьма большим. Для этого
лучше всего пользоваться методом gcount, так как он ещё вернёт количество байт,
которые были считаны по факту методом read. Сами эти фрагменты могут храниться в
специальном буфере, как и в примере из лекций, но его размер и второй аргумент к
функции read надо рассчитать так, чтобы выводились все символы, без обрезки
последней буквы. Файл можно открыть в бинарном формате.


Что оценивается

Показ файла на экране должен соответствовать тому, что мы наблюдаем в
стандартном блокноте.
*/