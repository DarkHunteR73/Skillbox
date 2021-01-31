#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "=================\n";
    std::cout << "Майские праздники\n";
    std::cout << "=================\n\n";

    std::cout << "Какой день недели был 1 мая? (1-7)? ";
    int modifier;
    std::cin >> modifier;    

    std::cout << "Какое сегодня число? ";
    int day;    
    std::cin >> day;

    if (day >= 1 && day <= 31 && modifier >= 1 && modifier <= 7) {
        modifier--;
        if (day >= 1 && day <= 5 || day >= 8 && day <= 10) {
            std::cout << "Выходной!\n";
        }
        else if ((day + modifier) % 7 == 6 || (day + modifier) % 7 == 0) {
            std::cout << "Выходной!\n";
        }
        else {
            std::cout << "Рабочий день\n";
        }
    }
    else {
        std::cout << "Ошибка ввода\n";
    }
    return 0;
}