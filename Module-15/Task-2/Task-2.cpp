#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec{ 2, 7, 11, 15 };
	const int result = 9;
	int first = 0, second = 0;

	for (int i = 0; i < vec.size() - 1; ++i)
	{
		for (int j = i + 1; j < vec.size(); ++j)
		{
			if (vec[i] + vec[j] == result)
			{
				first = vec[i];
				second = vec[j];
			}
		}
	}

	std::cout << first << ' ' << second << std::endl;
}

//Задача 2
//
//Вам даётся массив целых чисел и одно число -- результат.Необходимо найти в массиве 2 числа, сумма которых будет давать результат, и вывести их на экран.
//Гарантируется, что только одна пара чисел в массиве даёт в сумме результат.
//
//Пример:
//
//a = { 2, 7, 11, 15 }. Результат = 9
//
//2 + 7 = 9, так что надо вывести числа 2 и 7