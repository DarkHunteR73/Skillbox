#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "*********************\n";
    std::cout << "      Военкомат\n";
    std::cout << "  Набираем лётчиков\n";
    std::cout << "*********************\n\n";

// Получаем данные от пользователя
    std::cout << "Введите количество часов налёта: ";
    int flyHours;
    std::cin >> flyHours;

    std::cout << "Введите рост: ";
    int height;
    std::cin >> height;
    
    std::cout << "Введите вес: ";
    int weight;
    std::cin >> weight;

    std::cout << "Введите количество рук: ";
    int handsCount;
    std::cin >> handsCount;

    std::cout << "Введите количество ног: ";
    int legsCount;
    std::cin >> legsCount;

    std::cout << "Введите цвет глаз: ";
    std::string eyeColor;
    std::cin >> eyeColor;

// Проверяем критерии
    int decision;

    if (flyHours > 100) decision = 1;
    else {
        if (height < 145 || height > 165) decision = 0;
        if (weight < 45 || weight > 65) decision = 0;
        if (handsCount != legsCount) decision = 0;
        if (eyeColor == "зеленый") decision = 0;
    }

// Выносим решение
    if (decision != 0) std::cout << "Годен\n\n";
    else std::cout << "Не годен\n\n";

    return 0;
}