#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    const int xSize = 15, ySize = 20;
    int x = xSize / 2;
    int y = ySize / 2;
    std::cout << "Марсоход находится на позиции " << x << ", " << y << ", введите команду: ";
    std::string input;

    for (;;)
    {
        std::cin >> input;
        if (input == "w" && y < ySize) y++;
        else if (input == "s" && y > 0) y--;
        else if (input == "a" && x > 0) x--;
        else if (input == "d" && x < xSize) x++;
        std::cout << "Марсоход находится на позиции " << x << ", " << y << ", введите команду: ";
    }
}