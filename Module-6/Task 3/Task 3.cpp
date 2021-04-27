#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Счетчик знаков в числе\n\n";
    std::cout << "Введите число: ";
    int number;
    std::cin >> number;

    int count = 0;
    while (number != 0)
    {
        number /= 10;
        count++;
    }
    std::cout << "Число состоит из " << count << " знаков\n\n";
    return 0;
}