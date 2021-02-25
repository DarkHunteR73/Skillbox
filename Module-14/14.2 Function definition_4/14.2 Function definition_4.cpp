#include <iostream>

float abs(float x)
{
    return x >= 0 ? x : -x;
}

float sin(float x)
{
    float result = 0.0;
    float add = x;
    int count = 0;

    while (abs(add) >= 1e-6)
    {
        result += add;
        ++count;
        add *= (-1) * x * x / (2 * count) / (2 * count + 1);
    } 
    return result;
}

int main()
{
    std::cout << sin(3.1415);
}