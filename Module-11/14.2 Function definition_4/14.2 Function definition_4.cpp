#include <iostream>

float absolute(float x)
{
    return x >= 0 ? x : -x;
}

float sinus(float x)
{
    float result = 0.0;
    float add = x;
    int count = 0;

    while (absolute(add) >= 1e-6)
    {
        result += add;
        ++count;
        add *= (-1) * x * x / (2 * count) / (2 * count + 1);
    } 
    return result;
}

int main()
{
    std::cout << sinus(3.1415);
}