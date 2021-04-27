#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Введите напоминание: ";
    std::string remind;
    std::getline(std::cin, remind);

    std::cout << "Сколько раз напомнить? ";
    int count;
    std::cin >> count;

    while (count > 0)
    {
        std::cout << remind << std::endl;
        count--;
    }
    return 0;
}