#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Введите ширину рамки: ";
	int width;
	std::cin >> width;

	std::cout << "Введите высоту рамки: ";
	int height;
	std::cin >> height;

	for (int row = 1; row <= height; row++)									//Высота
	{		
		for (int line = 1; line <= width; line++)							//Ширина
		{
			if (line == 1 || line == width) std::cout << "|";
			else if ((line > 1 && line < width) && (row == 1 || row == height)) std::cout << "-";
			else std::cout << " ";
		}
		std::cout << "\n";
	}
	return 0;
}