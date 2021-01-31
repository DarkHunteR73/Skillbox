#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Числа Фибоначчи\n\n";
    int count, requiredIterations = 0;
    int const limit = 2147483647;
    do
    {
        std::cout << "Введите номер числа: ";
        std::cin >> requiredIterations;
        if (requiredIterations > 0) break;
        std::cout << "Ошибка! Значение должно быть больше нуля.\n";
    } while (requiredIterations <= 0);

    count = 1;
    int sum = 0, prev = 0, next = 1;
    bool outOfRange = false;
    do
    {
        outOfRange = prev > limit / 2;
        sum = prev + next;
        prev = next;
        next = sum;
        count++;
    } while (count < requiredIterations && !outOfRange);
    if (!outOfRange) std::cout << sum << "\n";
    else std::cout << "Ошибка! Выход за пределы int\n";
    return 0;
}