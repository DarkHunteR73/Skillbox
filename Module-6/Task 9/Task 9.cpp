#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Калькулятор вкладов\n\n";

    int deposit, interestRate, desiredDeposit;
    std::cout << "Введите сумму вклада: ";
    std::cin >> deposit;
    std::cout << "Процентная ставка: ";
    std::cin >> interestRate;
    std::cout << "Введите желаемую сумму на счету: ";
    std::cin >> desiredDeposit;

    int requiredYears = 0;
    while (deposit < desiredDeposit)
    {
        deposit += deposit * interestRate / 100;
        requiredYears++;
    }
    std::cout << "Через " << requiredYears << " лет сумма депозита достигнет желаемого размера\n";
    return 0;
}