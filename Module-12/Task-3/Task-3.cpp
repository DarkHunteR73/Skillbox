#include <iostream>

int main()
{
    std::cout << "How many people live in the building? ";
    int totalResidents;
    std::cin >> totalResidents;

    int floors[5]{};
    int currentResidents = 0;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "How many people are on the " << i + 1 << " floor now? ";
        std::cin >> floors[i];
        currentResidents += floors[i];
    }

    if (currentResidents > totalResidents)
    {
        std::cout << "\nAttention! Current number of residents is more than registered.\n"
            << "Possible presence of strangers!\n";
    }
    else
    {
        float isolation = currentResidents * 100.0f / totalResidents;
        std::cout << "\nLevel of isolation is: " << isolation << "%\n";
    }
}

//Задача 3. Уровень самоизоляции
//
//В одной отдельно взятой пятиэтажке проживает N зарегистрированных жильцов - данное число требуется ввести с самого начала программы.На каждом из этажей сейчас
//находится Ni людей.Это число также требуется ввести вначале.Используя все эти данные требуется вычислить общий уровень самоизоляции в доме, как процентное отношение
//общего числа людей, которые сейчас находятся на этажах к общему количеству жильцов, зарегистрированных в нём.Для этого можно использовать формулу : (сумма Ni * 100) / N