﻿#include <iostream>

void arrayInitializer(int array[][12], int num)
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            array[i][j] = num;
        }
    }
}

void printArray(int array[][12])
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 12; ++j) std::cout << array[i][j] << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    int cutlery[2][12];
    arrayInitializer(cutlery, 3);
    for (int i = 0; i < 2; ++i) ++cutlery[i][0];

    int dishes[2][12];
    arrayInitializer(dishes, 2);
    for (int i = 0; i < 2; ++i) ++dishes[i][0];

    int chairs[2][12];
    arrayInitializer(chairs, 1);

    ++chairs[0][4];
    --cutlery[1][2];
    --cutlery[0][0];
    ++cutlery[1][2];
    --dishes[0][0];

    std::cout << "Cutlery:" << std::endl;
    printArray(cutlery);

    std::cout << "Dishes:" << std::endl;
    printArray(dishes);

    std::cout << "Chairs:" << std::endl;
    printArray(chairs);
}

/*
Задача 1. Банкетный стол

    По поводу успешного прохождения двумерных массивов собирается банкет, организуется стол на 12 персон, 2 из них - это места VIP, они расположены рядом
друг к другу во главе стола.Стол протяжённый в длину, места расположены в два ряда.Каждый пришедший должен быть “упакован” соответствующим образом.
Во - первых столовые приборы - их три на каждого человека(вилка, ложка, нож), плюс одна маленькая дополнительная ложечка для VIP - персон, для десерта.
Это необходимо обеспечить.Следом тарелки, каждому по две - для первого и второго блюда, для VIP персон + 1 тарелка для десерта.Ну и конечно стул - один
для каждого, минимум!Заведите соответствующие двумерные массивы для количества приборов, посуды и стульев и проинициализируйте их как следует.

    Однако, это ещё не всё.В ходе банкета, уже после инициализации, происходят некоторые события.Пришедшая на 5 - ое место первого ряда дама пришла вместе с 
ребёнком и поэтому на данное место был приставлен ещё один стул.С третьего места во втором ряду в неизвестном направлении была украдена ложка.После этого 
одна из VIP персон(любая) поделилась своей ложкой с тем у кого она пропала, а сам стал есть суп десертной.За ненадобностью официант забрал у него одну
десертную тарелку, ибо есть десерт ложкой, которая побывала уже в супе - не комильфо.Больше без происшествий!
*/