#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Сколько чисел хотите сложить? ";
    int count, sum = 0;
    std::cin >> count;

    for (int num; count > 0; count--)
    {
        std::cout << "Введите число: ";
        std::cin >> num;
        sum += num;
    }
    std::cout << "Сумма всех чисел равна: " << sum << "\n";
}