#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    int bacteries, antibiotic, hours;

    std::cout << "Введите количество бактерий: ";
    std::cin >> bacteries;
    std::cout << "Сколько капель антибиотика: ";
    std::cin >> antibiotic;

    std::cout << "\nАнтибиотик действует 10 часов\n\n";
    for (hours = 10; hours >= 0; hours--)
    {
        bacteries *= 2;
        bacteries -= (antibiotic * hours);
        if (bacteries <= 0) 
        {
            bacteries = 0;
            break;
        }
        std::cout << "Осталось " << hours << " часов. Бактерий: " << bacteries << "\n";
    }
    if (bacteries == 0) std::cout << "Осталось " << hours << " часов. Все бактерии убиты\n";
    else std::cout << "Действие антибиотика закончилось.\n";
    return 0;
}