﻿#include <iostream>

int rabbitJump(int pos, int maxJump = 3) {
  if (pos < 0) return 0;
  if (pos == 0) return 1;

  int sum = 0;

  for (int i = 1; i <= maxJump; ++i) {
    sum += rabbitJump(pos - i, maxJump);
  }

  return sum;
}

int main() {
  int n;
  std::cout << "Input number of steps: ";
  std::cin >> n;

  int k;
  std::cout << "Input max length of jump (0 to use default=3): ";
  std::cin >> k;

  if (k == 0) {
    std::cout << rabbitJump(n);
  } else {
    std::cout << rabbitJump(n, k);
  }
}

/*
Задача 3

Что нужно сделать

Кролик сидит на нулевой ступеньке большой лестницы. Он может прыгать на одну или
более ступенек вверх, но не далее чем на k. Кролик хочет допрыгать до n-й
ступеньки, но может сделать это большим количеством способов.

Напишите рекурсивную функцию, которая принимает число n типа int и число k —
максимальную длину прыжка, а возвращает количество способов, которым кролик
может доскакать до n-й ступеньки. Если максимальная длина прыжка не задана —
считать её равной трём.

Пример:

Ввод: 3, 2

Вывод: 3

Пояснение: (1,2), (2,1), (1,1,1)


Чек-лист для проверки задачи

    Функция принимает корректные типы данных, тип возвращаемого значения —  int.
    Функция не использует библиотек кроме <iostream>.
    Функция рекурсивная.
    Функция содержит значение по умолчанию.
*/