#include <iostream>

int gcd(int a, int b)
{
    if (b > a) std::swap(a, b);
    if (a % b == 0) return b;

    return gcd(b, a % b);
}

int main()
{
    int a = 144, b = 1320;
    std::cout << gcd(a, b) << std::endl;
}

