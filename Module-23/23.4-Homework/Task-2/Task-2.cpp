﻿#include <iostream>

#define TRAIN(call) train##_##call

int train[10];
int train_total;

void train_fill() {
  for (int i = 0; i < 10; ++i) {
    std::cout << "Enter the number of passengers in the train car " << i + 1
              << ": ";
    std::cin >> train[i];
    train_total += train[i];
  }
}

void train_result() {
  std::cout << "Overcrowded wagons: ";

  for (int i = 0; i < 10; ++i) {
    if (train[i] > 20) {
      std::cout << i + 1 << ' ';
    }
  }
  std::cout << std::endl;

  std::cout << "Wagons with empty seats: ";

  for (int i = 0; i < 10; ++i) {
    if (train[i] < 20) {
      std::cout << i + 1 << ' ';
    }
  }
  std::cout << std::endl;
}

int main() {
  TRAIN(fill)();
  TRAIN(result)();
  std::cout << "Total passengers: " << TRAIN(total) << std::endl;
}

//Задание 2. Анализ заполненности вагонов в поезде
//
//
//Что нужно сделать
//
//В поезде всего 10 вагонов.В каждом из этих вагонов может находиться до 20 - ти
//пассажиров — это оптимальное их количество.Проанализируйте количество людей в
//каждом из вагонов и сначала сообщите об излишне заполненных вагонах, далее о
//вагонах с пустыми пассажирскими местами.В заключении выведите общее количество
//пассажиров во всех вагонах.
//
//При старте программы пользователь вводит количество пассажиров в каждом из
//вагонов.Замечания о вагонах должны выводиться в стандартную консоль.
//
//При выполнении задания пользоваться for - циклами напрямую не разрешается,
//только опосредованно, через макросы.
//
//
//Советы и рекомендации
//
//С помощью макроса реализуйте модульный способ вызова функции - предиката над
//элементами массива.Сами функции - предикаты реализуйте отдельно, в виде
//обычных классических функций(не макросов).
//
//Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью
//“Shift - Shift->Preprocess current TU”.
//
//
//Что оценивается
//
//Корректность работы программы.Модульность и элегантность решения с помощью
//макросов.
