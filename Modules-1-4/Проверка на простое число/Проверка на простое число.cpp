#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите число: ";
    int number;
    std::cin >> number;

    int current = 2;
    bool found = false;
    while (current * current <= number && !found)
    {        
        found = number % current == 0;
        current++;                
    }
    if (!found)std::cout << "Число простое\n";
    else std::cout << "Число не простое\n";
    return 0;
}