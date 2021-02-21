﻿#include <iostream>

int main()
{
    int number;
    
    while (true)
    {
        std::cout << "Input number (1-3999): ";
        std::cin >> number;
        if (number > 0 && number <= 3999) break;
        std::cout << "Wrong input. Try again.\n";
    }

    std::string romanNumber = "";

    while (number > 0)
    {
        if (number / 1000 >= 1) {
            number -= 1000;
            romanNumber += 'M';
            continue;
        }   
        if (number / 900 >= 1) {
            number -= 900;
            romanNumber += "CM";
        }
        if (number / 500 >= 1) {
            number -= 500;
            romanNumber += 'D';
        }
        if (number / 400 >= 1) {
            number -= 400;
            romanNumber += "CD";
        }
        if (number / 100 >= 1) {
            number -= 100;
            romanNumber += 'C';
            continue;
        }
        if (number / 90 >= 1) {
            number -= 90;
            romanNumber += "XC";
        }
        if (number / 50 >= 1) {
            number -= 50;
            romanNumber += 'L';
        }
        if (number / 40 >= 1) {
            number -= 40;
            romanNumber += "XL";
        }
        if (number / 10 >= 1) {
            number -= 10;
            romanNumber += 'X';
            continue;
        }
        if (number / 9 >= 1) {
            number -= 9;
            romanNumber += "IX";
        }
        if (number / 5 >= 1) {
            number -= 5;
            romanNumber += 'V';
        }
        if (number / 4 >= 1) {
            number -= 4;
            romanNumber += "IV";
        }
        if (number / 1 >= 1) {
            number -= 1;
            romanNumber += 'I';
            continue;
        }
    }
    std::cout << romanNumber << std::endl;
    return 0;
}
/*
5. Из обычных чисел — в римские

Напишите программу, которая переводит данное пользователем число в римскую запись. Например, 19 в римской записи
представляется как XIX.

Римская запись числа получается по следующим правилам. Сначала в ней идут буквы, описывающие количество тысяч в числе. 
Затем идут буквы, обозначающие количество сотен, затем буквы, обозначающие количество десятков, и в конце — буквы,
обозначающие количество единиц. Для записи используются следующие буквы: 1 — I, 5 — V, 10 — X, 50 — L, 100 — C,
500 — D и 1000 — M. Число получается как сумма значений использованных в нем букв, за тем исключением, что если
буква с меньшим значением идет после буквы с большим значением, то ее значение вычитается из значения числа. 
Вычитание используется только в случае, когда надо передать цифру 4 или 9, в остальных случаях используется сложение.
(Например, 9 обозначается как IX, 40 обозначается как XL). В числе запрещено писать более трех одинаковых букв подряд
(таким образом, максимальное число, которое можно записать по этим правилам, равно 3999).

Программе на вход дается целое число из диапазона от 1 до 3999. (Вы можете считывать его как число или как строку, 
если так удобнее.)

Программа должна вывести римскую запись данного числа.


Примеры:

Ввод: 351

Вывод: CCCLI


Ввод: 449

Вывод: CDXLIX


Ввод: 1313

Вывод: MCCCXIII


Ввод: 2020

Вывод: MMXX
*/