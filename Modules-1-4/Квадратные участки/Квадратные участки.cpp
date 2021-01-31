#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Проверим, является ли введенная площадь квадратом\n"
        << "Введите площадь: ";
    int square, result = 0;
    std::cin >> square;
    const int limit = 1000000;
    bool found = false;

    for (int side = 1; result <= limit && !found; side++)
    {
        result = side * side;
        found = result == square;
    }

    if (found) std::cout << "Является\n";
    else std::cout << "Не является\n";

    return 0;
}