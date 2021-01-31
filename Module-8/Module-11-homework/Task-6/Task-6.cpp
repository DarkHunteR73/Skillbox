#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    int x = 149597870;
    int y = 0;
    std::string input;

    for (;;)
    {
        std::cout << "Марсоход находится на позиции " << x << ", " << y << ", введите команду: ";
        std::cin >> input;
        if (input == "w") y++;
        else if (input == "s") y--;
        else if (input == "a") x--;
        else if (input == "d") x++;
        else
        {
            std::cout << "Неизвестная команда! Введите снова.\n";
            continue;
        }
    }
}