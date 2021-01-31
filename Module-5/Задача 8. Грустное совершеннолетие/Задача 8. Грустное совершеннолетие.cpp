#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "==================================================\n";
    std::cout << "Рассчитаем, можно ли продавать алкоголь посетителю\n";
    std::cout << "==================================================\n\n\n";

    std::cout << "Введите дату рождения посетителя: ";
    int birthDateDay, birthDateMonth, birthDateYear;
    std::cin >> birthDateDay >> birthDateMonth >> birthDateYear;

    std::cout << "Введите текущую дату ";
    int currentDay, currentMonth, currentYear;
    std::cin >> currentDay >> currentMonth >> currentYear;

    if (currentYear - birthDateYear > 18 || (currentYear - birthDateYear == 18 && (currentMonth > birthDateMonth || currentMonth == birthDateMonth && currentDay > birthDateDay))) {
        std::cout << "Можно продавать алкоголь\n";
    }
    else {
        std::cout << "Алкоголь продавать нельзя\n";
    }
    return 0;
}