#include <iostream>
#include <vector>

// Крайне занятный алгоритм
void quick_sort(std::vector<int>& vec, int left, int right)
{
	int i = left, j = right;
	int pivot = std::abs(vec[(left + right) / 2]);

	while (i <= j)
	{
		while (std::abs(vec[i]) < pivot) ++i;
		while (std::abs(vec[j]) > pivot) --j;

		if (i <= j)
		{
			std::swap(vec[i], vec[j]);
			++i;
			--j;
		}
	}

	if (left < j)
		quick_sort(vec, left, j);
	if (i < right)
		quick_sort(vec, i, right);
}

int main()
{
	std::vector<int> vec{ -100,-50, -5, 1, 10, 15 };

	quick_sort(vec, 0, vec.size() - 1);

	//for (int i = 0; i < vec.size(); ++i)
	//{
	//	for (int j = 0; j < vec.size() - i - 1; ++j)
	//	{
	//		if (std::abs(vec[j]) > std::abs(vec[j + 1]))
	//		{
	//			std::swap(vec[j], vec[j + 1]);
	//		}
	//	}
	//}

	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << ' ';
	}
}

//Задача 4
//
//Вам даётся массив целых чисел, отсортированных по возрастанию.Необходимо вывести его на экран отсортированным в порядке возрастания модуля чисел
//
//Пример :
//
//Массив{ -100,-50, -5, 1, 10, 15 }
//
//Вывод: 1, -5, 10, 15, -50, -100
//
//Задание со звёздочкой : оптимизировать решение четвёртой задачи, чтобы оно совершало как можно меньше операций