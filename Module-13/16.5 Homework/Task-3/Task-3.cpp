﻿#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec(20);

	int num = 0, pos = 0, size = 0;
	while (num != -1)
	{
		std::cout << "Enter the number: ";
		std::cin >> num;
		vec[pos] = num;

		if (size < 20) ++size;
		++pos;
		pos %= 20;
	}

	if (size < 20) pos = 0;

	std::cout <<"\nDatabase content:"<< std::endl;

	for (int i = 0; i < size; ++i)
	{
		std::cout << vec[pos] << ' ';
		++pos;
		pos %= 20;
	}

	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get();
}

//Задача 3.
//
//В базу данных, являющуюся вектором, с клавиатуры приходят целочисленные значения, и помещаются в конец.Однако, эта база может хранить только 20 элементов,
//а дальше необходимо будет удалять элементы, которые лежат в базе дольше всех.
//
//При вводе - 1 с клавиатуры необходимо вывести всё содержимое базы данных(то есть 20 или менее элементов).При выводе элементы должны быть в том порядке,
//в котором они добавлялись в базу данных.
//
//Попробуйте написать максимально оптимизированное решение данной задачи, чтобы совершалось как можно меньше расширений и перемещений элементов внутри вектора.