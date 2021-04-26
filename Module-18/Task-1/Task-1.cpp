#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec{ -2,1,-3,4,-1,2,1,-5,4 };

	int index_begin = 0, index_end = 0, max_res = 0;

	for (int i = 0; i < vec.size(); ++i)
	{
		int res = 0;
		for (int j = i; j < vec.size(); ++j)
		{
			res += vec[j];
			if (res > max_res)
			{
				max_res = res;
				index_begin = i;
				index_end = j;
			}
		}
	}

	std::cout << index_begin << ' ' << index_end << std::endl;
}

//Задача 1
//
//Вам даётся массив целых чисел.Необходимо найти такие два индекса i и j в этом массиве, что сумма a[i], a[i + 1], a[i + 2], … a[j] будет максимально
//возможной и вывести их.
//
//Пример:
//
//a = { -2,1,-3,4,-1,2,1,-5,4 }
//
//Тогда наибольшая сумма последовательных элементов находится между индексами 3 и 6 : {4, -1, 2, 1}, сумма = 6. Необходимо вывести 3 и 6