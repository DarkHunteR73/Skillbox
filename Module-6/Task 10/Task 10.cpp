#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Загадайте число от 0 до 63.\n\n";
    int minimumValue = 0, maximumValue = 63, mediumValue = maximumValue / 2;
    std::string answer;

    while (maximumValue > minimumValue)
    {
        mediumValue = (maximumValue + minimumValue) / 2;             // Среднее арифметическое
        std::cout << "Ваше число больше " << mediumValue << "?\n";
        std::getline(std::cin,answer);
        if (answer == "да")
        {
            minimumValue = mediumValue;
            minimumValue++;
        }
        else if (answer == "нет")
        {
            maximumValue = mediumValue;
        }
        else std::cout << "Отвечать нужно \"да\" или \"нет\"\n";
    }
    std::cout << "\n\nОтвет: " << maximumValue << "\n";
    return 0;
}