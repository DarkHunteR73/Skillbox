#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "==============\n";
	std::cout << "Нули и единицы\n";
	std::cout << "==============\n\n";
	std::cout << "Введите число: ";
	int number, result = 0;
	std::cin >> number;

	bool found = false;
	while (number != 0 && !found)
	{
		result = number % 10;
		found = number % 10 > 1;
		number /= 10;
	}

	if (!found) std::cout << "Число состоит из нулей и единиц\n";
	else std::cout << "Число состоит не только из нулей и единиц\n";

	return 0;
}
