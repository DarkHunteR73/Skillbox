#include <iostream>

long long fib(int n)
{
	if (n == 1 || n == 2) return 1;

	for (int i = 1; i <= n; ++i)
	{
		return fib(n - 1) + fib(n - 2);
	}
}

int main()
{
	std::cout << fib(20);
}