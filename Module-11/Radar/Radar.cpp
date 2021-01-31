#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите расстояние до объекта: ";
    float distance;
    std::cin >> distance;

    std::cout << "Введите угол: ";
    float angle;
    std::cin >> angle;
    angle /= 57.296;

    float x, y;
    x = std::cos(angle) * distance;
    y = std::sin(angle) * distance;

    std::cout << "Координаты объекта: (" << x << ", " << y << ")\n";
}
