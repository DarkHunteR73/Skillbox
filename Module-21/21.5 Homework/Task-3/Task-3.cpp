#include <cmath>
#include <iostream>

enum Mode { ADD = 1, SUBTRACT, SCALE, LENGTH, NORMALIZE };

struct Vector {
  double x = 0.0;
  double y = 0.0;
};

double vLength(Vector vec);

int main() {
  std::cout << "1. Add" << std::endl;
  std::cout << "2. Subtract" << std::endl;
  std::cout << "3. Scale" << std::endl;
  std::cout << "4. Length" << std::endl;
  std::cout << "5. Normalize" << std::endl;
  std::cout << "Select operation: ";

  int operation;
  while (true) {
    std::cin >> operation;

    if (operation >= 1 && operation <= 5) {
      break;
    } else {
      std::cerr << "Unknown operation! Please try again.";
      std::cout << "Select operation: " << std::endl;
    }
  }

  if (operation == ADD || operation == SUBTRACT) {
    std::cout << "Input first vector coordinates: ";
    Vector vec1;
    std::cin >> vec1.x >> vec1.y;

    std::cout << "Input second vector coordinates: ";
    Vector vec2;
    std::cin >> vec2.x >> vec2.y;

    if (operation == SUBTRACT) {
      vec2.x -= 2 * vec2.x;
      vec2.y -= 2 * vec2.y;
    }

    std::cout << "Result: (" << vec1.x + vec2.x << ';' << vec1.y + vec2.y << ')'
              << std::endl;
  } else {
    std::cout << "Input vector coordinates: ";
    Vector vec;
    std::cin >> vec.x >> vec.y;

    if (operation == SCALE) {
      std::cout << "Input scale: ";
      double val;
      std::cin >> val;

      std::cout << "Result: (" << vec.x * val << ';' << vec.y * val << ')'
                << std::endl;
    } else {
      double len = vLength(vec);

      if (operation == LENGTH) {
        std::cout << "Result: " << len << std::endl;
      } else {
        std::cout << "Result: (" << vec.x / len << ';' << vec.y / len << ')'
                  << std::endl;
      }
    }
  }
}

double vLength(Vector vec) {
  vec.x = std::abs(vec.x);
  vec.y = std::abs(vec.y);

  if (vec.x >= 0 && vec.x < 0.000001) {
    return vec.y;
  } else if (vec.y >= 0 && vec.y < 0.000001) {
    return vec.x;
  } else {
    return std::hypot(vec.x, vec.y);
  }
}

/*
Задание 3. Реализация математического вектора


Что нужно сделать

Реализуйте структуру двумерного математического вектора и основные операции над
ним. Обе координаты вектора (x и y) должны быть вещественными числами.

Вначале программы пользователь вводит команду, которая соответствует требуемой
операции. Далее, в зависимости от операции, пользователь вводит её аргументы.
Это могут быть как вектора, так и обычные, скалярные значения. В результате в
стандартный вывод помещается результат. Это тоже может быть или вектор, или
скаляр.


Реализуйте следующие операции в виде отдельных функций:

        Сложение двух векторов — команда add.
        Вычитание двух векторов — команда subtract.
        Умножение вектора на скаляр — команда scale.
        Нахождение длины вектора — команда length.
        Нормализация вектора — команда normalize.


Что оценивается

Корректность работы программы и всех операций над вектором или векторами.
*/