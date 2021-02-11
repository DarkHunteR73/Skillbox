#include <iostream>
#include <algorithm>

int main()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    cout << "Введите два числа: ";
    float number1, number2;
    cin >> number1 >> number2;
    cout << "Наибольшее число: " << max(number1, number2) << endl;
    return 0;
}
