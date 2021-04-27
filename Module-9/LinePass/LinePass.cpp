#include <iostream>

int main()
{
    std::string str;
    std::cout << "Input string: ";
    std::cin >> str;

    bool flag = true;
    for (int i = 0; i < str.length() && flag; i++)
    {
        if (str[i] < 'a' || str[i] > 'z') flag = false;
    }

    for (int i = 0; i + 1 < str.length() && flag; i++)
    {
        if (str[i] > str[i + 1]) flag = false;
    }

    if (flag) std::cout << "Yes!\n";
    else std::cout << "No!\n";

    return 0;
}
