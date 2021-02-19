#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Введите число: ";
	int number, count = 0;
	std::cin >> number;

	int result = 1;
	while (result < number)
	{
		result *= 2;
		count++;
	}
	if (result == number) std::cout << number << " является " << count << "-й степенью двойки\n";
	else std::cout << number << " не является степенью двойки\n";
	return 0;

}