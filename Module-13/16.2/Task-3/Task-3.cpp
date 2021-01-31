#include <iostream>
#include <vector>

std::vector<int> addToPosition(std::vector<int> vec, int num, int pos)
{
	if (num < 0) return vec;
	else
	{
		if (pos > vec.size()) pos = vec.size();
		std::vector<int> newVec(vec.size() + 1);

		if (vec.empty())
		{
			newVec[0] = num;
		}
		else
		{
			for (int i = 0; i < pos; ++i)
			{
				newVec[i] = vec[i];
			}
			newVec[pos - 1] = num;
			for (int i = pos; i < newVec.size(); ++i)
			{
				newVec[i] = vec[i - 1];
			}
		}
		return newVec;
	}
}

int main()
{
	std::vector<int> line{};

	int num = 0, pos = 0;
	while (num >= 0)
	{
		std::cout << "Enter your number: ";
		std::cin >> num;

		if (num >= 0 && !(line.empty()))
		{
			std::cout << "Enter position: ";
			std::cin >> pos;
		}

		line = addToPosition(line, num, pos);
	}

	for (int i = 0; i < line.size(); ++i)
	{
		std::cout << line[i] << ' ';
	}
}
/*
Задание 3. Роботы и коррупция*
Улучшите электронную очередь для роботов. К нам приходят роботы разного социального статуса. Каждый робот вводит не только свой уникальный номер, но и свое место
в очереди. Например, пусть в нашей очереди 10 роботов и к нам приходит 11-й. Сначала он вводит свой номер, как и раньше, а затем свое место в очереди - например, 5. 
В этом случае он должен оказаться в очереди пятым, а все остальные, начиная со старого пятого - подвинуться дальше в конец очереди.
Реализуйте функцию std::vector<int> add_to_position(std::vector vec, int val, int position)
*/