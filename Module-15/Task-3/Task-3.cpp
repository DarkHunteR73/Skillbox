#include <iostream>
#include <vector>

// Крайне занятный алгоритм
void quick_sort(std::vector<int>& vec, int left, int right)
{
	int i = left, j = right;
	int pivot = vec[(left + right) / 2];

	while (i <= j)
	{
		while (vec[i] < pivot) ++i;
		while (vec[j] > pivot) --j;

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
	std::vector<int> vec{ 4,33,54,-7,56,81,-23,15,29,31,65,-90,118,554,99,112,421 };

	while (true)
	{
		std::cout << "Input number:";
		int num = 0;
		std::cin >> num;

		if (num == -1)
		{
			if (vec.size() < 5)
			{
				std::cerr << "Error! You need to enter at least five numbers" << std::endl;
			}
			else
			{
				quick_sort(vec, 0, vec.size() - 1);

				//for (int i = 0; i < vec.size(); ++i)
				//{
				//	for (int j = 0; j < vec.size() - i - 1; ++j)
				//	{
				//		if (vec[j] > vec[j + 1])
				//		{
				//			std::swap(vec[j], vec[j + 1]);
				//		}
				//	}
				//}

				std::cout << vec[4] << std::endl;
			}
		}
		else if (num == -2)
		{
			return 0;
		}
		else
		{
			vec.push_back(num);
		}
	}
}

//Задача 3
//
//С клавиатуры вводятся числа.Когда пользователь вводит - 1 --необходимо выводить на экран пятое по возрастанию число среди введённых.
//Когда пользователь вводит - 2 --программа завершает работу.
//
//Пример:
//
//ввод: 7 5 3 1 2 4 6 - 1
//
//вывод : 5 (в отсортированном виде массив выглядит так : {1, 2, 3, 4, 5, 6, 7})
//
//ввод : 1 1 1 - 1
//
//вывод : 2 (в отсортированном виде массив выглядит так : {1, 1, 1, 1, 2, 3, 4, 5, 6, 7})
//
//ввод - 2
//
//завершение программы