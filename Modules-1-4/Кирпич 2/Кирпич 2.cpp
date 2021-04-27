#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите размеры кирпича: ";
    int a, b, c;
    std::cin >> a >> b >> c;

    std::cout << "Введите размеры отверстия: ";
    int x, y;
    std::cin >> x >> y;

    if (a <= x && b <= y || a <= y && b <= x) {
        std::cout << "\nПролезет\n\n";
    }
    else if (b <= x && c <= y || b <= y && c <= x) {
        std::cout << "\nПролезет\n\n";
    }
    else if (a <= x && c <= y || a <= y && c <= x) {
        std::cout << "\nПролезет\n\n";
    }
    else std::cout << "\nНе пролезет\n\n";
}