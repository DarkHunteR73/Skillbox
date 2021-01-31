#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите размеры первой коробки: ";
    int a, b, c;
    std::cin >> a >> b >> c;

    std::cout << "Введите размеры второй коробки: ";
    int m, n, k;
    std::cin >> m >> n >> k;

    if (a <= m && b <= n && c <= k || a <= n && b <= m && c <= k) {
        std::cout << "\nВлезет\n\n";
    }
    else if (b <= m && c <= n && a <= k || b <= n && c <= m && a <= k) {
        std::cout << "\nВлезет\n\n";
    }
    else if (a <= m && c <= n && b <= k || a <= n && c <= m && b <= k) {
        std::cout << "\nВлезет\n\n";
    }
    else std::cout << "\nНе влезет\n\n";
    return 0;
}