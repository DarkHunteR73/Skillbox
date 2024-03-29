﻿#include "Task-1.h"

#include "point.h"

int main() {
  Point scalpelPointA, scalpelPointB;
  Point suturePointA, suturePointB;
  std::string command;

  std::cout << "Enter \"scalpel\" to start." << std::endl;

  while (command != "scalpel") {
    getCommand(command);
  }

  while (true) {
    if (command == "scalpel") {
      scalpel(scalpelPointA, scalpelPointB);
    } else if (command == "hemostat") {
      hemostat();
    } else if (command == "tweezers") {
      tweezers();
    } else if (command == "suture") {
      suture(suturePointA, suturePointB);

      if (isEqualPoints(scalpelPointA, scalpelPointB, suturePointA,
                        suturePointB)) {
        std::cout << "Operation is finished!" << std::endl;
        std::exit(EXIT_SUCCESS);
      }
    } else {
      std::cout << "Unknown command!" << std::endl;
    }

    getCommand(command);
  }
}

//Задание 1. Симулятор проведения операций
//
//    Что нужно сделать
//
//        Реализуйте простой симулятор проведения медицинской операции у
//            пациента.Пользователь выступает в роли хирурга,
//    который запрашивает инструменты у ассистента и применяет их сообразно
//        ситуации
//            .
//
//    Пользователь взаимодействует с программой с помощью команд
//            .Команды не имеют сложной встроенной логики
//    : они просто принимают нужные данные в качестве аргументов и выводят
//          сообщения в консоль о выполнении
//            .Данные команд — это одна или две двумерные точки в формате double
//            с
//                координатами X и Y соответственно
//            .
//
//      scalpel — принимает на вход две двумерные координаты начала и конца
//          разреза или линии отсечения.При выполнении этой команды в консоль
//              выводится сообщение о том,
//    что был сделан разрез между введёнными координатами.
//
//    hemostat — эта команда принимает на вход одну точку,
//    в которой требуется сделать зажим,
//    о чём также сообщает в консоль.
//
//    tweezers — пинцет,
//    как и зажим,
//    принимает одну точку для применения.Сообщение об этом выводится в консоль.
//
//    suture — команда хирургической иглы,
//    которая делает шов между двумя указанными точками
//            .
//
//        Операция всегда начинается с команды scalpel и заканчивается командой
//            suture.Для окончания работы программы их параметры -
//        точки при этом должны совпасть
//            .
//
//        Программу требуется реализовать именно с помощью одного заголовочного
//            файла и одного файла с исходным кодом(cpp)
//            .В заголовочном файле должны находиться функции
//        - инструменты.В основном файле — основная логика программы,
//    обработка ввода пользователя.
//
//    Советы и рекомендации
//
//    Для удобства создайте структуру с типом двумерной координаты(точки)
//        вместе с набором функций для ввода этой координаты из консоли,
//    её вывода в консоль и сравнения на предмет равенства
//            .Для этих целей удобнее всего создать ещё один заголовочный файл.
//
//        Что оценивается
//
//        Корректность работы программы и составленного CMake
//        - файла конфигурации проекта.