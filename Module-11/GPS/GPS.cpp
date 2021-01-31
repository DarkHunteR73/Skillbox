#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите координаты: ";
    float x, y;
    std::cin >> x >> y;

    float distance = std::sqrt(x * x + y * y);

    std::cout << "Расстояние до точки: " << distance;
    return 0;
}