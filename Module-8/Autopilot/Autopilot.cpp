#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    cout << "Введите угол тангажа: ";
    int angleDeg;
    cin >> angleDeg;

    angleDeg %= 360;

    float angleRad = angleDeg / 57.2957f;
    
    if (angleRad >= -0.28 && angleRad <= 0.28) cout << "Угол безопасен\n";
    else cout << "Угол небезопасен\n";
}
