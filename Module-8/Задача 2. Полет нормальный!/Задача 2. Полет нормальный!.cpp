#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите скорость (км/ч): ";
    int speed;
    std::cin >> speed;

    std::cout << "Введите высоту (м): ";
    int altitude;
    std::cin >> altitude;

    if ((speed > 750 && speed < 850) && (altitude > 9000 && altitude < 9500)) {
        std::cout << "\nПравильный эшелон\n\n";
    }
    else {
        std::cout << "\nНеправильный эшелон\n\n";
    }

    return 0;
}