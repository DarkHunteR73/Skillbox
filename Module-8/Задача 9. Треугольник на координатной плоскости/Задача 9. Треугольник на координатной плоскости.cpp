#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите координаты точки A: ";
    int ax, ay;
    std::cin >> ax >> ay;

    std::cout << "Введите координаты точки B: ";
    int bx, by;
    std::cin >> bx >> by;

    std::cout << "Введите координаты точки C: ";
    int cx, cy;
    std::cin >> cx >> cy;

    if (ax == bx && ay == by || bx == cx && by == cy || ax == cx && ay == cy) {
        std::cout << "No\n";
    }
    else if ((ax - bx) / (ay - by) == (bx - cx) / (by - cy) || (bx - cx) / (by - cy) == (ax - cx) / (ay - cy) || (ax - bx) / (ay - by) == (ax - cx) / (ay - cy)) {
        std::cout << "No\n";
    }
    else {
        std::cout << "Yes\n";
    }
    return 0;
}