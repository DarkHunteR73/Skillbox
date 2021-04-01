#include <iostream>

int main()
{
	for (int row = 0; row <= 20; row++)
	{
		for (int line = 1; line <= 51; line++)
		{
			if (row == 0 && line == 26) std::cout << "^";
			else if ((row < 10 || row > 10) && line == 26) std::cout << "|";
			else if (row == 10 && line == 51)std::cout << ">";
			else if (row == 10 && line == 26) std::cout << "+";
			else if (row == 10 && (line < 26 || line>26)) std::cout << "-";
			else std::cout << " ";
		}
		std::cout << "\n";
	}
}