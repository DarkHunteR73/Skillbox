#include <iostream>
#include <string>

int main()
{
    std::cout << "Input integer and fractional part: ";
    int intPart, fracPart;
    std::cin >> intPart >> fracPart;

    std::string tmp = std::to_string(intPart) + '.' + std::to_string(fracPart);

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