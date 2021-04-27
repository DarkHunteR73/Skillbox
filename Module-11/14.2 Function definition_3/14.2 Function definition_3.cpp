#include <iostream>

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

int main()
{
    std::string str;
    std::cin >> str;

    bool correct = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (!isDigit(str[i])) correct = false;
    }

    std::cout << (correct ? "Yes" : "No") << '\n';
}
