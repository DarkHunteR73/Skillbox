#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    int x = 0, y = 0;
    std::cout << "������� ���������� x: ";
    std::cin >> x;
    std::cout << "������� ���������� y: ";
    std::cin >> y;

    if (x == 0 && y == 0) std::cout << "������ ���������\n";
    if (x > 0 && y > 0) std::cout << "������ ��������\n";
    if (x > 0 && y < 0) std::cout << "�������� ��������\n";
    if (x > 0 && y == 0) std::cout << "������� ������ � �������� ���������\n";
    if (x < 0 && y > 0) std::cout << "������ ��������\n";
    if (x < 0 && y < 0) std::cout << "������ ��������\n";
    if (x < 0 && y == 0) std::cout << "������� ������ � ������� ���������\n";
    if (x == 0 && y > 0) std::cout << "������� ������ � ������ ���������\n";
    if (x == 0 && y < 0) std::cout << "������� ������� � �������� ���������\n";

    return 0;
}