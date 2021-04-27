#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    int x = 0, y = 0;
    std::cout << "Введите координату x: ";
    std::cin >> x;
    std::cout << "Введите координату y: ";
    std::cin >> y;

    if (x == 0 && y == 0) std::cout << "Начало координат\n";
    if (x > 0 && y > 0) std::cout << "Первая четверть\n";
    if (x > 0 && y < 0) std::cout << "Четвёртая четверть\n";
    if (x > 0 && y == 0) std::cout << "Граница первой и четвёртой четвертей\n";
    if (x < 0 && y > 0) std::cout << "Вторая четверть\n";
    if (x < 0 && y < 0) std::cout << "Третья четверть\n";
    if (x < 0 && y == 0) std::cout << "Граница второй и третьей четвертей\n";
    if (x == 0 && y > 0) std::cout << "Граница первой и второй четвертей\n";
    if (x == 0 && y < 0) std::cout << "Граница третьей и четвёртой четвертей\n";

    return 0;
}