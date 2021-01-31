#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "***************\n";
	std::cout << "    Кукушка\n";
	std::cout << "****************\n\n";

	std::cout << "Который час? ";
	int currentHour;
	std::cin >> currentHour;

	int count = 0;
	if (currentHour >= 1 && currentHour <= 12)
	{
		while (count != currentHour)
		{
			std::cout << "Ку-ку\n";
			count++;
		}
	}
	else std::cout << "Ошибка ввода\n";
	return 0;
}