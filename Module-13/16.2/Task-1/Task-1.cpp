#include <iostream>
#include <vector>

std::vector<int> add(std::vector<int> vec, int num)
{
	std::vector<int> newVec(vec.size() + 1);

	for (int i = 0; i < vec.size(); ++i)
	{
		newVec[i] = vec[i];
		newVec[vec.size()] = num;
	}

	return newVec;
}

int main()
{    
    int number = 0;
	std::vector<int> line{ 0 };

	while (number != -1)
	{
		std::cout << "Input your number: ";
		std::cin >> number;

		line = add(line, number);
	}

	for (int i = 1; i < line.size() - 1; ++i)
	{
		std::cout << line[i] << ' ';
	}
}