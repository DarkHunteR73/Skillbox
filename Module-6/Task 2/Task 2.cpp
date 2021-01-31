#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "*************************\n";
    std::cout << "      Бот-коллектор\n";
    std::cout << "*************************\n\n";

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
    
    while (payment < debt)
    {        
        std::cout << userName << ", ваша задолженность составляет " << debt << " рублей. Сколько рублей вы внесете прямо сейчас, чтобы ее погасить?\n>";
        std::cin >> payment;
        while (payment < 0)
        {
            std::cout << "Ошибка! Введите снова\n>";
            std::cin >> payment;
        }        
    }
    std::cout << "Благодарим за погашение задолженности!\n";
    return 0;
}