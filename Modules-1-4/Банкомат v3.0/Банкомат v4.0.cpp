#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "==================\n";
    std::cout << "     Банкомат\n";
    std::cout << "==================\n\n";


    int sum = 0, pin;
    std::cout << "Введите пин-код: ";
    std::cin >> pin;

    while (pin != 0) {
        sum += pin % 10;
        pin /= 10;
    }

    if (sum == 42) {
        std::cout << "Пин-код принят. Добро пожаловать!\n\n";
        std::cout << "Сколько денег хотите снять? ";
        int withdrawMoney;
        int count;
        std::cin >> withdrawMoney;

        if (withdrawMoney < 150000) {
            if (withdrawMoney % 100 == 0) {
                if (withdrawMoney / 5000 >= 1) {
                    count = withdrawMoney / 5000;
                    std::cout << "Купюр по 5000: " << count << "\n";
                    withdrawMoney = withdrawMoney - 5000 * count;
                }
                if (withdrawMoney / 2000 >= 1) {
                    count = withdrawMoney / 2000;
                    std::cout << "Купюр по 2000: " << count << "\n";
                    withdrawMoney = withdrawMoney - 2000 * count;
                }
                if (withdrawMoney / 1000 >= 1) {
                    count = withdrawMoney / 1000;
                    std::cout << "Купюр по 1000: " << count << "\n";
                    withdrawMoney = withdrawMoney - 1000 * count;
                }
                if (withdrawMoney / 500 >= 1) {
                    count = withdrawMoney / 500;
                    std::cout << "Купюр по 500: " << count << "\n";
                    withdrawMoney = withdrawMoney - 500 * count;
                }
                if (withdrawMoney / 200 >= 1) {
                    count = withdrawMoney / 200;
                    std::cout << "Купюр по 200: " << count << "\n";
                    withdrawMoney = withdrawMoney - 200 * count;
                }
                if (withdrawMoney / 100 >= 1) {
                    count = withdrawMoney / 100;
                    std::cout << "Купюр по 100: " << count << "\n";
                    withdrawMoney = withdrawMoney - 100 * count;
                }
            }
            else {
                std::cout << "Ошибка ввода. Введите сумму, кратную 100\n";
            }
        }
        else {
            std::cout << "Ошибка. За один раз возможно снять не более 150000.\n\n";
        }
    }
    else {
        std::cout << "Неправильный пин-код!\n";
    }
    return 0;
}