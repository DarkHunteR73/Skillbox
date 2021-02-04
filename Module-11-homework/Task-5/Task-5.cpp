#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    float downloadSize, downloadSpeed;
    while (true)
    {
        cout << "Укажите размер файла для скачивания: ";
        cin >> downloadSize;

        cout << "Скорость скачивания Мб/с: ";
        cin >> downloadSpeed;

        if (downloadSize > 0 && downloadSpeed > 0) break;
        cout << "Ошибка! Введённые значения должны быть больше нуля.\n";
    }


    for (float currentDownload = 0.0f, timer = 1; currentDownload < downloadSize; timer++)
    {
        currentDownload += downloadSpeed;
        if (currentDownload > downloadSize) currentDownload = downloadSize;
        float downloadPercent = 100.0f * currentDownload / downloadSize;
        cout << " Прошло " << setw(3) << timer << " сек. Скачано " << setw(5)
            << currentDownload << " из " << downloadSize << " MB. (" << round(downloadPercent) << "%)\n";
    }
    return 0;
}

/*
    Задача 5. Убийца Steam

    Вы пишете программу-инсталлятор для компьютерной игры. Пока обновление скачивается, пользователю нужно показать 
прогресс загрузки, чтобы он мог решить, подождать ему у экрана компьютера или заварить чай.

    Напишите программу, принимающую на вход размер файла обновления в мегабайтах и скорость интернет-соединения в
мегабайтах в секунду. В каждую секунду программа показывает, сколько процентов от общего объема обновления уже скачано,
до тех пор, пока файл не загрузится. После установки обновления программа выводит время в секундах, которое заняло 
скачивание. Обеспечьте контроль ввода. 


Пример
Ввод:

Укажите размер файла для скачивания: 123.

Какова скорость вашего соединения? 27.


Вывод:

Прошло 1 сек. Скачано 27 из 123 МБ (22%).

Прошло 2 сек. Скачано 54 из 123 МБ (44%).

Прошло 3 сек. Скачано 81 из 123 МБ (66%).

Прошло 4 сек. Скачано 108 из 123 МБ (88%).

Прошло 5 сек. Скачано 123 из 123 МБ (100%).
*/