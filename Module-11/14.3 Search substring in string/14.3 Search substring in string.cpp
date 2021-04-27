#include <iostream>

bool isMatch(std::string text, std::string word, int pos)
{
    for (int i = 0; i < word.length(); ++i)
    {
        if (i + pos >= text.length() || word[i] != text[i + pos]) return false;
    }
    return true;
}

int find(std::string text, std::string word)
{
    for (int startPos = 0; startPos + word.length() <= text.length(); ++startPos)
    {
        if (isMatch(text, word, startPos)) return startPos;
    }
    return -1;
}

int main()
{
    std::string text, word;
    std::cout << "Input text: ";
    std::cin >> text;
    std::cout << "Input word: ";
    std::cin >> word;


    std::cout << (find(text, word) != -1 ? "Yes" : "No") << '\n';
}
