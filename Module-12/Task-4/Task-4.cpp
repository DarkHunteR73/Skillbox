﻿#include <iostream>

int main()
{
    float channels[10]{};
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Tune " << i + 1 << " channel: ";
		std::cin >> channels[i];
	}

	int userChoice = 1;
	while (userChoice != 0)
	{
		std::cout << "Select channel(1-10): ";
		std::cin >> userChoice;
		if (userChoice > 0 && userChoice <= 10)
		{
			std::cout << userChoice << " channel. " << channels[userChoice - 1] << " MHz" << std::endl;
		}
		else if (userChoice == 0) return 0;
		else std::cout << "Error!" << std::endl;
	}
}
/*
Задача 4. Радио-приёмник

В радио-приёмнике настроено 10 частот-каналов, представленные в виде массива. Каждая из настроек частоты это число с плавающей точкой. 
Настройка производится при старте приёмника. Приёмник проигрывает текущий настроенный канал, устанавливая текущую активную чистоту, 
которая и показывается пользователю. Требуется организовать безопасный доступ к каналам приёмника. Если канал набираемый пользователем
находится за пределами массива каналов, приёмник не переключается и выводит сообщение об ошибке. Если пользователь вводит 0, приёмник отключается.
*/