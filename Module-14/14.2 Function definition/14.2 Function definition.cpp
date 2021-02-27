#include <iostream>
#include <iomanip>

float distance(float sec)
{
	return 9.81 * sec * sec / 2;
}

int main()
{
	for (float t = 0.0; t <= 5; t += 0.5)
	{
		std::cout << std::setw(4) << t << "  " << distance(t) << '\n';
	}
}
