#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    int year;

    std::cout << "Введите год: ";
    std::cin >> year;

    if (year % 4 == 0 && year % 100 != 0 ^ year % 400 == 0) std::cout << "В году 366 дней (год високосный)\n";
    else std::cout << "В году 365 дней\n";
    return 0;
}