﻿#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    int leftBorder = 0, rightBorder = 0;
    float point = 0.0f;

    while (true)
    {
        cout << "Введите левую границу градиента: ";
        cin >> leftBorder;

        cout << "Введите правую границу градиента: ";
        cin >> rightBorder;

        cout << "Введите положение точки между границами: ";
        cin >> point;

        if (leftBorder >= 0 && rightBorder >= 0 && leftBorder <= 255 && rightBorder <= 255 && point >= 0 && point <= 1)
        {
            break;
        }
        cout << "Ошибка! Введите снова.\n";
    }

    float brightness = leftBorder + ((rightBorder - leftBorder) * point);
    cout << "Яркость точки: " << brightness;
}

/*Задача 4. Убийца Photoshop
    Вы разрабатываете новый крутой графический редактор. Один из инструментов редактора позволяет делать градиент — плавный
переход между двумя точками разной яркости. Яркость точки определяется целым числом от 0 до 255, где 0 — чёрный, 
255 — белый, а всё, что между ними — оттенки серого. 

Напишите код для расчёта яркости точки градиента между двумя заданными точками. Пользователь вводит яркость левой границы 
градиента, потом яркость правой границы и параметр: число от 0 до 1, которое означает интересующую нас точку. 
Например, если параметр равен 0.5, то искомая точка находится ровно посередине между левой и правой границами, 
если параметр равен 0, то искомая точка совпадает с левой границей, и, наконец, если параметр равен 1, то искомая точка 
совпадает с правой границей. Программа должна вывести число — яркость искомой точки. Обеспечьте контроль ввода. 


Пример
Ввод:

Введите яркость левую границу градиента: 10.

Введите правую границу градиента: 255.

Введите положение точки между границами: 0.7.


Вывод:

Яркость точки: 181.5.*/