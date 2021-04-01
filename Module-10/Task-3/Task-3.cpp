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

    int latteCounter = 0, americanoCounter = 0;
    for (;;)
    {
        std::cout << "\nКофемашина готова к работе.\n";
        std::cout << "---------------------------\n";
        std::cout << "1.Латте\n2.Американо\nВыберите напиток: ";
        int userChoise;
        std::cin >> userChoise;

        bool latteAvailable = (milkLevel >= 270 && waterLevel >= 30);
        bool americanoAvailable = (waterLevel >= 300);
        switch (userChoise)                                             // Ну очень хотелось Switch использовать =)
        {
        case 1:
        {
            if (latteAvailable)
            {
                milkLevel -= 270;
                waterLevel -= 30;
                std::cout << "Ваш латте готов\n\n";
                latteCounter++;
            }
            else if (milkLevel < 270)
            {
                std::cout << "Не хватает молока\n\n";
            }
            else
            {
                std::cout << "Не хватает воды\n\n";
            }
            break;
        }
        case 2:
        {
            if (americanoAvailable)
            {
                waterLevel -= 300;
                std::cout << "Ваш американо готов\n\n";
                americanoCounter++;
            }
            else
            {
                std::cout << "Не хватает воды\n\n";
            }
            break;
        }
        default:
        {
            std::cout << "Неизвестная команда\n\n";
            break;
        }
        }
        if (!latteAvailable && !americanoAvailable) break;
    }
    std::cout << "Ингредиенты закончились.\n";
    std::cout << "Приготовлено:\nЛатте - " << latteCounter << " чашек\nАмерикано - " << americanoCounter << " чашек\n\n";
    std::cout << "Осталось молока - " << milkLevel << " мл\n";
    std::cout << "Осталось воды - " << waterLevel << " мл\n";
    return 0;
}