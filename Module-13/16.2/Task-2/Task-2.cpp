#include <iostream>
#include <vector>

std::vector<int> add(std::vector<int> vec, int num)
{
	std::vector<int> newVec(vec.size() + 1);

	if (vec.empty())
	{
		newVec[0] = num;
	}
	else
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			newVec[i] = vec[i];
		}
		newVec[vec.size()] = num;
	}

	return newVec;
}

int main()
{
    std::vector<int> patientAge{};
    int age = 0;

    while (age >= 0)
    {
        std::cout << "Input age: ";
        std::cin >> age;

		patientAge = add(patientAge, age);
    }

	double sum = 0.0;
	int count = 0;

	for (int i = 0; i < patientAge.size() - 1; ++i)
	{
		sum += patientAge[i];
		++count;
	}

	std::cout << "\nAverage age is: " << sum / count << "\nPatients quantity: " << count << std::endl;
}
/*
Задание 2. Лечебница
Напишите программу для картотеки пациентов лечебницы. С клавиатуры вводится неизвестное количество целых положительных чисел - возрастов пациентов. 
Когда пациенты заканчиваются, медсестра вводит число -1. Это говорит программе о том, что пора заканчивать с приемом пациентов и переходить к расчету статистики.

Напишите программу, складывающую в вектор целые положительные числа, пока не поступит отрицательное число. После этого выведите среднее значение
всех введенных чисел и их количество.
*/