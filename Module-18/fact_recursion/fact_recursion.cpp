#include <iostream>
#include <climits>

uint64_t fact(uint64_t num)
{
	if (num == 0 || num == 1) return 1;
	return num * fact(num - 1);
}

int main()
{
	for (int i = 0; i <=20; ++i)
	{
		std::cout << i << '\t' << fact(i) << std::endl;
	}

	std::cout << "\nMAX\t" << UINT64_MAX << std::endl;
}
