#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");

	int userInput;
	do
	{
		std::cout << "Введите высоту: ";
		std::cin >> userInput;
		if (userInput > 0) break;
		std::cout << "Ошибка!\n";
	} while (true);

	for (int n = 1; n <= userInput; n++)						//Для строк
	{
		int c = 1;

		for (int i = 0; i < (userInput - n); i++)				//Для пробелов
		{
			std::cout << " ";
		}

		for (int k = 1; k <= n; k++)							//Для цифр
		{
			std::cout << c << " ";
			c = c * (n - k) / k;
		}

		std::cout << "\n";
	}
	return 0;
}
/*
			1
		   1 1
		  1 2 1
		 1 3 3 1
		1 4 6 4 1
*/