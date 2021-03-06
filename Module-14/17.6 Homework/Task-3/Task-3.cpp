﻿#include <iostream>
#include <iomanip>

int main()
{
	const int height = 5, width = 5;
	int num = 0;
	int arr[height][width];

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; ++j)
		{
			arr[i][i % 2 == 0 ? j : width - j - 1] = num++;
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cout << std::setw(3) << arr[i][j];
		}
		std::cout << std::endl;
	}

	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get();
}

//Задача 3. Проход змейкой
//
//    Довольно абстрактная, но интересная задача.У нас есть двумерный массив целых чисел размером 5 на 5 элементов.Его надо инициализировать и отобразить на экране.
//Особенность именно в способе этой инициализации.Элементы должны быть инициализированы не последовательно, а змейкой.Т.е.в конце каждой строки мы не должны 
//переходить к первому элементу следующей строки, но начнём наоборот — с последнего элемента и так далее.В итоге, в конечном отображении нашего массива числа 
//должны быть упорядочены по возрастанию но змеевидно от строки к строке.Сама же последовательность чисел — это простое линейное возрастание от 0 до 24, 
//для её учёта можно завести отдельную переменную.
//
//    Попытайтесь решить эту задачу, используя минимальное количество временных переменных и без условных переходов if.Если вы найдёте эту самую формулу индексации — 
//будет замечательно!Предупреждаю, она может быть весьма витиеватая.
//
//
//Итоговый результат :
//
//0 1 2 3 4
//
//9 8 7 6 5
//
//10 11 12 13 14
//
//19 18 17 16 15
//
//20 21 22 23 24
