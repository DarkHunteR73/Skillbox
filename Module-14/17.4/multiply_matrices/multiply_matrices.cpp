#include <iostream>
#include <iomanip>

int main()
{
	int a[4][4]{	{12,16,7,5},
					{3,8,6,9},
					{18,21,70,0},
					{4,0,5,1} };
	int b[4][4]{	{50,44,3,8},
					{75,81,64,56},
					{32,36,72,8},
					{6,0,0,4} };
	int c[4][4];

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			int sum = 0;
			for (int k = 0; k < 4; ++k)
			{
				sum += a[i][k] * b[k][j];
			}
			c[i][j] = sum;
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			std::cout << std::setw(5) << c[i][j];
		}
		std::cout << std::endl;
	}
}
