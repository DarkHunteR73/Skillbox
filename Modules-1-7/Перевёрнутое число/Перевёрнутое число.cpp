#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Введите число: ";
	int number;
	std::cin >> number;

	int result = 0;
	while (number != 0)
	{
		result = result * 10 + number % 10;		
		number /= 10;
	}
	std::cout << result;
	return 0;
}
