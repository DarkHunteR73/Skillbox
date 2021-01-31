﻿#include <iostream>

bool input_validator(std::string input) //Контроль ввода
{
    if (input.length() != 9) return false;
    for (int i = 0; i < input.length(); ++i)
    {
        if (input[i] != 'X' && input[i] != 'O' && input[i] != '.') return false;
    }
    return true;
}

char gamefield_scan(std::string input)  //Считывание игрового поля
{
    std::string win_combinations = "";
    char c = ' ';

    for (int i = 0; i < 3; ++i) //Вертикали
    {
        if (input[i] != '.' && input[i] == input[i + 3] && input[i] == input[i + 6])
        {
            c = input[i];
            win_combinations += c;
        }
    }

    for (int i = 0; i <= 6; i += 3) //Горизонтали
    {
        if (input[i] != '.' && input[i] == input[i + 1] && input[i] == input[i + 2])
        {
            c = input[i];
            win_combinations += c;
        }
    }

    if (input[0] != '.' && input[0] == input[4] && input[0] == input[8])    //Диагонали
    {
        c = input[0];
        win_combinations += c;
    }

    if (input[2] != '.' && input[2] == input[4] && input[2] == input[6])
    {
        c = input[2];
        win_combinations += c;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    if (win_combinations.length() == 0)
    {
        c = 'N';    //"Nobody"
    }
    else
    {
        for (int i = 0; i < win_combinations.length() && c != 'E'; ++i)
        {
            if (win_combinations[i] != c)
            {
                c = 'E';    //"Error"
            }
        }
    }
    return c;
    ///////////////////////////////////////////////////////////////////////////////////////
}

void game_result(std::string input)
{
    int x_count = 0, o_count = 0;

    if (input_validator(input))
    {
        for (int i = 0; i < input.length(); ++i)
        {
            if (input[i] == 'X') ++x_count;
            else if (input[i] == 'O') ++o_count;
        }

        if (gamefield_scan(input) == 'X' && x_count - o_count == 1)
        {
            std::cout << "\nPetya won\n";
        }
        else if (gamefield_scan(input) == 'O' && x_count == o_count)
        {
            std::cout << "\nVanya won\n";
        }
        else if (gamefield_scan(input) == 'N' && (x_count == o_count || x_count - o_count == 1))
        {
            std::cout << "\nNobody\n";
        }
        else std::cout << "\nIncorrect\n";
    }
    else std::cout << "\nIncorrect\n";
}

int main()
{
    std::string str1;
    std::cout << "Input line 1: ";
    std::cin >> str1;

    std::string str2;
    std::cout << "Input line 2: ";
    std::cin >> str2;

    std::string str3;
    std::cout << "Input line 3: ";
    std::cin >> str3;

    std::string result = str1 + str2 + str3;
    game_result(result);
}
/*
Задание 2. Анализ результатов игры в крестики-нолики


Что нужно сделать

    Петя и Вася играли в крестики-нолики и не стёрли результаты своей игры. Теперь перед вами табличка 3 × 3, которая
осталась после их поединка. Вы хотите понять, выиграл ли кто-то из них или они не доиграли.

    На вход программе даётся три строки, кодирующие верхнюю, среднюю и нижнюю строчки игрового поля. Крестик
обозначается символом X (английская заглавная буква X), нолик — символом O (заглавная латинская буква O), пустая клетка —
точкой.

    Если ввод некорректен, то есть такая таблица не могла получиться в ходе настоящей игры, то надо написать в ответ
слово Incorrect.

    Если таблица корректна и выиграли крестики, то нужно вывести в ответ слова Petya won, если нолики — то Vanya won,
а иначе (то есть они не доиграли или сыграли вничью) надо написать Nobody.


Примеры

X..

OXO

OOO

Ответ: Incorrect (потому что ноликов в конце игры не может быть больше, чем крестиков).


X..

.X.

OO.

Ответ: Nobody (потому что они не доиграли).


XXO

XOX

OOX

Ответ: Nobody (потому что это ничья).


XO.

XO.

X.O

Ответ: Incorrect (крестики уже победили, и ноликов не может быть столько же).


OX.

XOX

X.O

Ответ: Incorrect (потому что нолики выиграли за три хода, и на поле за это время не могло успеть появиться четыре крестика).


..X

OX.

X.O

Ответ: Petya won.


0..

...

...

Ответ: Incorrect (потому что допускаются только символы X, O и точка, а цифра 0 не является допустимым символом).


Советы и рекомендации

    Активно используйте оператор индексации строки str[i], но помните что индексы начинаются с нуля, а не с единицы.
    Для того, чтобы обращаться к элементам игрового поля, стоит написать отдельную функцию получения элемента поля по
    его координатам (x, y). В таком случае, часть алгоритмов поиска победителя можно обобщить.
    Функции проверки поля на корректность можно отделить от функций и алгоритмов проверки победителя.
    При достаточной модульности функций, некоторые операции можно реализовать через уже существующие процедуры. К примеру,
    если уже есть проверка победителя в строке и имеется функция получения колонки по индексу, то функцию поиска
    победителя в колонке можно реализовать через обе них.
    Проход по диагонали поля можно осуществить в цикле, используя счётчик цикла в качестве обоих координат элемента.
    Для второй диагонали нужно обратить одну из координат (2 - x или 2 - y).

    Общие условия некорректности поля таковы:
        Выявлено несколько победителей одновременно
        Нолики победили, а крестиков больше чем ноликов
        Крестики победили, а ноликов столько же или больше
        Нолики и крестики победили несколько раз
        На поле есть невалидные символы


Что оценивается

Корректность работы программы по анализу игры на различных вводных данных.


Как отправить задание на проверку

Выполните задание в Google Документах, откройте доступ для комментирования. Ссылку пришлите через форму для сдачи
домашнего задания.


*/