#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Счастливый билетик\n\n";
    std::cout << "Введите шестизначный номер: ";
    int number1, number2;
    std::cin >> number1;

    number2 = number1 % 1000;       // Разбиваем номер на две части *** ***
    number1 /= 1000;
    
    int sum1 = 0, sum2 = 0;
    while (number1 != 0 || number2 != 0)    // Суммируем цифры
    {
        sum1 += number1 % 10;   sum2 += number2 % 10;
        number1 /= 10;          number2 /= 10;
    }
    if (sum1 == sum2) std::cout << "Ура! Счастливый билетик!\n";
    else std::cout << "Эх. Не в этот раз.\n";
    return 0;
}