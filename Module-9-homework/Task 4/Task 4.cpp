#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "**************************\n";
    std::cout << "    Бот-коллектор v2.0\n";
    std::cout << "**************************\n\n";

    std::cout << "Как вас зовут? ";
    std::string userName;
    std::getline(std::cin, userName);

    std::cout << "Сумма долга: ";
    int debt = 0, payment = 0;
    std::cin >> debt;
    while (debt < 0)
    {
        std::cout << "Ошибка! Введите снова: ";
        std::cin >> debt;
    }

    while (debt > 0)
    {
        std::cout << userName << ", ваша задолженность составляет " << debt << " рублей. Сколько рублей вы внесете прямо сейчас, чтобы ее погасить?\n>";
        std::cin >> payment;
        while (payment < 0)
        {
            std::cout << "Ошибка! Введите снова\n>";
            std::cin >> payment;
        }
        debt -= payment;
    }
    if (debt < 0) std::cout << "Благодарим за погашение задолженности!\nОстаток на счету: " << -debt << " рублей.\n";
    else std::cout << "Благодарим за погашение задолженности!\n";
    return 0;
}