#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	int userInput;
	do
	{
		std::cout << "Введите высоту: ";
		std::cin >> userInput;
		if (userInput > 0) break;
		std::cout << "Ошибка!\n";
	} while (userInput <= 0);

	for (int line = 1; line <= userInput; line++)										//Строки
	{
		for (int iteration = 1; iteration < (userInput - line + 1); iteration++)		//Пробелы
		{
			std::cout << " ";
		}
		for (int iteration = 1; iteration <= line * 2 - 1; iteration++)					//########
		{
			std::cout << "#";
		}
		std::cout << "\n";
	}
	return 0;
}