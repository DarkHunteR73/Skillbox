#include <iostream>

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

    int thousands = number / 1000;
    int hundreds = number % 1000 / 100;
    int dozens = number % 100 / 10;
    int ones = number % 10;

    std::string romanNumber = "";

    for (size_t i = 0; i < thousands; ++i)
    {
        romanNumber += 'M';
    }

    if (hundreds == 4 || hundreds == 9) romanNumber += 'C';
    if (hundreds >= 4 && hundreds <= 8) romanNumber += 'D';
    if (hundreds == 9) romanNumber += 'M';
    if (hundreds % 5 < 4)
    {
        for (size_t i = 0; i < hundreds % 5; ++i)
        {
            romanNumber += 'C';
        }
    }

    if (dozens == 4 || dozens == 9) romanNumber += 'X';
    if (dozens >= 4 && dozens <= 8) romanNumber += 'L';
    if (dozens == 9) romanNumber += 'C';
    if (dozens % 5 < 4)
    {
        for (size_t i = 0; i < dozens % 5; ++i)
        {
            romanNumber += 'X';
        }
    }

    if (ones == 4 || ones == 9) romanNumber += 'I';
    if (ones >= 4 && ones <= 8) romanNumber += 'V';
    if (ones == 9) romanNumber += 'X';
    if (ones % 5 < 4)
    {
        for (size_t i = 0; i < ones % 5; ++i)
        {
            romanNumber += 'I';
        }
    }

    std::cout << romanNumber << std::endl;
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