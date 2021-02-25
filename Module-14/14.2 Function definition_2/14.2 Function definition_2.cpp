#include <iostream>

int max(int x, int y)
{
    return x > y ? x : y;
}

int max3(int x, int y, int z)
{
    //return x > y ? max(x, z) : max(y, z);
    return max(max(x, y), z);
}

int main()
{
    int a = 65;
    int b = 5;
    int c = 442;
    std::cout << max3(a, b, c) << '\n';
}
