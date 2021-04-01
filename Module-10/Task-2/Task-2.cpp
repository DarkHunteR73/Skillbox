#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    int waterLevel = 0, milkLevel = 0;
    std::cout << "Заправьте кофемашину водой и молоком.\n";
    std::cout << "-------------------------------------\n";
    do
    {
        std::cout << "Введите объём воды: ";
        std::cin >> waterLevel;

        std::cout << "Введите объём молока: ";
        std::cin >> milkLevel;
        if (milkLevel > 0 && waterLevel > 0) break;
        std::cout << "Ошибка!\n";
    } while (true);

    for (;;)
    {
        std::cout << "\nКофемашина готова к работе.\n";
        std::cout << "---------------------------\n";
        std::cout << "1.Латте\n2.Американо\nВыберите напиток: ";
        int userChoise;
        std::cin >> userChoise;

        if (userChoise == 1)
        {
            if (milkLevel >= 270 && waterLevel >= 30)
            {
                std::cout << "Ваш напиток готов\n\n";
                milkLevel -= 270;
                waterLevel -= 30;
            }
            else if (milkLevel < 270) std::cout << "Не хватает молока\n\n";
            else std::cout << "Не хватает воды\n\n";
        }
        else if (userChoise == 2)
        {
            if (waterLevel >= 300)
            {
                std::cout << "Ваш напиток готов\n\n";
                waterLevel -= 300;
            }
            else std::cout << "Не хватает воды\n\n";
        }
        else std::cout << "Неизвестная команда\n\n";
    }

}