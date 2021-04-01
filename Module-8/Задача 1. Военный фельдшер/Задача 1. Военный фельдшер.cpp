#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "==============================\n";
    std::cout << "       Военный фельдшер\n";
    std::cout << "==============================\n\n";
    std::cout << "Проверяем снаряжение...\n";

    std::cout << "Сколько осталось медицинского спирта (мл)? ";
    int ethanol;
    std::cin >> ethanol;

    std::cout << "Сколько осталось медицинских аптечек? ";
    int firstAidKit;
    std::cin >> firstAidKit;

    if (ethanol >= 2000 && firstAidKit >= 5) {
        std::cout << "Можно выходить работать с ранеными\n\n";
    }
    else {
        std::cout << "Необходимо пополнить припасы, прежде чем работать с ранеными\n\n";
    }

    return 0;
}