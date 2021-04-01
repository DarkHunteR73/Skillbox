#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите цену товара: ";
    int price;
    std::cin >> price;

    if (price >= 11 && price <= 20) {
        std::cout << price << " рублей\n";
    }
    else if (price % 10 == 1) {
        std::cout << price << " рубль\n";
    }
    else if (price % 10 >= 2 && price % 10 <= 4) {
        std::cout << price << " рубля\n";
    }
    else {
        std::cout << price << " рублей\n";
    }
    return 0;
}
