#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    float force = 0.0f, mass = 0.0f, time = 0.0f;
    while (true)
    {
        cout << "Введите силу тяги: ";
        cin >> force;
        cout << "Введите массу: ";
        cin >> mass;
        cout << "Введите время: ";
        cin >> time;
        if (force > 0 && mass > 0 && time > 0) break;
        cout << "Ошибка! Значения должны быть положительными.\n";
    }

    float acceleration = force / time, distance = (acceleration * pow(time, 2)) / 2;
    cout << "Расстояние: " << distance << " м.\n";
    return 0;
}
