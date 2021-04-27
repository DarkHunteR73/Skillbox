#include <iostream>

int main()
{
    std::string str;
    std::cout << "Input string: ";
    std::cin >> str;

    bool palindrome = true;
    int lastIndex = str.length() - 1;

    for (int i = 0; i < str.length() / 2 && palindrome; i++)
    {
        if (str[i] != str[lastIndex - i]) palindrome = false;
    }

    if (palindrome) std::cout << "Yes!\n";
    else std::cout << "No!\n";

    return 0;
}
