#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Введите ширину: ";
	int width;
	std::cin >> width;

	std::cout << "Сколько восклицательных знаков нужно? ";
	int signs;
	std::cin >> signs;

	for (int line = 0; line < width; line++)
	{
		int evenSignCorrection = 0;
		if (signs % 2 == 0) evenSignCorrection = 1;
		if (line >= width / 2 - signs / 2 && line <= width / 2 + signs / 2 - evenSignCorrection) std::cout << "!";
		else std::cout << "~";
	}
	std::cout << "\n";
}