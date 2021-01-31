#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    int x = 0, y = 0;
    std::cout << "Введите координату x: ";
    std::cin >> x;
    std::cout << "Введите координату y: ";
    std::cin >> y;

    if (x > 0) {
        if (y > 0) std::cout << "Первая четверть\n";
        else if (y < 0) std::cout << "Четвёртая четверть\n";
        else std::cout << "Граница первой и четвёртой четвертей\n";
    }
    else if (x < 0) {
        if (y > 0) std::cout << "Вторая четверть\n";
        else if (y < 0) std::cout << "Третья четверть\n";
        else std::cout << "Граница второй и третьей четвертей\n";
    }
    else {
        if (y > 0) std::cout << "Граница первой и второй четвертей\n";
        else if (y < 0) std::cout << "Граница третьей и четвёртой четвертей\n";
        else std::cout << "Начало координат\n";
    }
    return 0;
}