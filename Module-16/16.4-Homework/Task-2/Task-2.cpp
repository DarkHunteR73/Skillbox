#include <iostream>
#include <string>

bool isCorrect(std::string str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			std::cerr << "Wrong input! Try again." << std::endl;
			return false;
		}
	}
	return true;
}

int main()
{
	int intPart;
	std::string fracPart;

	do
	{
		std::cout << "Input integer and fractional part: ";
		std::cin >> intPart >> fracPart;
	} while (!isCorrect(fracPart));

	std::string tmp = std::to_string(intPart) + '.' + fracPart;

	double result = std::stod(tmp);
	std::cout << "The result is: " << result << std::endl;
}

//Сшиватель дробных чисел
//
//Что нужно сделать
//
//Надо написать небольшую программу.Из целой и дробной частей числа, которые в отдельности вводит пользователь надо составить 
//новое число с плавающей точкой(типа double) и вывести это число обратно в консоль, для проверки.Целая часть - это та, часть числа, 
//которая находится до точки(запятой), дробная - после.