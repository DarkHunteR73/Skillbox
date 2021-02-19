#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите число: ";
    int num;
    std::cin >> num;

    std::cout << "Введите количество первых степеней числа: ";
    int count;
    std::cin >> count;

    for (int answer = 1; count > 0; count--)
    {
        answer *= num;
        std::cout << answer << std::endl;
    }
    return 0;
}