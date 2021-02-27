#include <iostream>

bool isPrime(int n)
{
    for (int d = 2; d * d <= n; ++d)
    {
        if (n % d == 0) return false;
    }
    return n > 1;
}

int main()
{
    std::cout << "Inpit numbers: ";
    int a, b;
    std::cin >> a >> b;

    int count = 0;
    for (int i = a; i <= b; ++i)
    {
        if (isPrime(i))
        {
            ++count;
        }
    }
    std::cout << count << std::endl;
}
