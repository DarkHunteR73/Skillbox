#include <iostream>

int main()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    int initialAmplitude = 0;
    float stopAmplitude = 0.0f;
    while (true)
    {
        cout << "Введите начальную амплитуду маятника: ";
        cin >> initialAmplitude;

        cout << "Введите конечную амплитуду: ";
        cin >> stopAmplitude;

        if (initialAmplitude > 0 && stopAmplitude > 0.0f) break;
        
        cout << "Ошибка! Введите снова.\n";
    }

    int pendulumSwing = 1;
    for (float currentAmplitude = initialAmplitude; currentAmplitude > stopAmplitude; pendulumSwing++)
    {
        currentAmplitude -= currentAmplitude * 0.084f;
    }
    cout << "Маятник качнулся " << pendulumSwing << " раз до конечной амплитуды\n";
    return 0;
}
/*Задача 9. Маятник

    Известно, что амплитуда качающегося маятника с каждым разом затухает на 8,4% от амплитуды прошлого колебания. 
Если качнуть маятник, он, строго говоря, никогда не остановится: его амплитуда будет уменьшаться до тех пор, пока мы не 
сочтём такой маятник остановившимся. Напишите программу, определяющую, сколько раз качнётся маятник, прежде чем он,
по нашему мнению, остановится. Программа получает на вход начальную амплитуду колебания в сантиметрах и конечную 
амплитуду его колебаний, которая считается остановкой маятника. Обеспечьте контроль ввода.*/