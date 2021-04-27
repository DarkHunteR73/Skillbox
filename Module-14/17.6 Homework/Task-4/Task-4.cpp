#include <iostream>

void initializeArray(int arr[][4], char ch)
{
	std::cout << "Enter matrice " << ch << ':' << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "Enter line " << i + 1 << ": ";
		std::cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
	}
	std::cout << std::endl;
}

int main()
{
	int arrA[4][4], arrB[4][4];
	initializeArray(arrA, 'A');
	initializeArray(arrB, 'B');

	bool equal = true;
	for (int i = 0; i < 4 && equal; ++i)
	{
		for (int j = 0; j < 4 && equal; ++j)
		{
			if (arrA[i][j] != arrB[i][j]) equal = false;
		}
	}

	if (equal) std::cout << "\nMatrices are equal" << std::endl;
	else std::cout << "\nMatrices are not equal" << std::endl;

	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get();
}

/*
Задача 4. Равенство матриц

Требуется реализовать небольшую программу для сравнения двух двумерных матриц размерами 4х4 на предмет их полного равенства. 
Программа принимает на вход две целочисленные матрицы A и B, которые вводятся с помощью std::cin и сравнивает их на предмет полного равенства. 
Если матрицы равны, то об этом сообщается в стандартном выводе. Алгоритм должен быть по возможности оптимальным и не проводить лишних операций.
*/