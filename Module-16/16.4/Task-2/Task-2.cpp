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
		
		while (line.size() != 0 && line[line.size() - 1] < num)
		{
			line.pop_back();
		}
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

//Задание 2
//Робот приходит в очередь и заставляет уходить из конца очереди всех, чей номер меньше, чем у него, а потом становится в очередь сам.
//Последний робот будет иметь номер - 1 (и, соответственно, не сможет никого выгнать, так как остальные имеют положительные номера).
//Когда он пришёл, нужно вывести все номера в очереди на экран.
