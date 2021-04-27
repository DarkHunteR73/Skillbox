#include <iostream>
#include <vector>

int main()
{
    std::vector<int> line{};

    int num = 0;
	while (num != -1)
	{
		std::cout << "Enter your number: ";
		std::cin >> num;
		line.push_back(num);
	}

	for (int i = 0; i < line.size(); ++i)
	{
		std::cout << line[i] << ' ';
	}
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get();
}

//Задание 1
//С помощью push_back() реализуйте очередь из роботов - андроидов.Роботы приходят в очередь и называют(вводят с клавиатуры) 
//свои порядковые номера(целые положительные).Последний робот в очереди всегда имеет номер - 1. Когда он пришёл, необходимо вывести на экран все номера в очереди.