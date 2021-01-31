#include <iostream>

int main()
{
    std::string text, word;
    std::cout << "Input text: ";
    std::cin >> text;
    std::cout << "Input word: ";
    std::cin >> word;

    bool found = false;
    for (int startPos = 0; startPos + word.length() <= text.length() && !found; startPos++)
    {
        bool match = true;
        for (int i = 0; i < word.length() && match; i++)
        {
            if (word[i] != text[i + startPos]) match = false;
        }

        if (match) found = true;
    }

    if (found) std::cout << "Yes!\n";
    else std::cout << "No!\n";
}
