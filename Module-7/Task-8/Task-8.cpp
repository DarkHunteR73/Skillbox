#include <iostream>

int main()
{
	for (int row = 1; row <= 3; row++)
	{		
		for (int line = 1; line <= 12; line++)
		{
			if (line == 1 || line == 12) std::cout << "|";
			else if ((row == 1 || row == 3) && (line > 1 && line < 12)) std::cout << "-";
			else if (row == 2 && line == 3)
			{
				std::cout << "Grigoriy";
				line += 7;
			}
			else std::cout << " ";
		}
		std::cout << "\n";
	}
	return 0;
}