#include <iostream>

int main()
{
    std::string text;
    std::cout << "Input text: ";
    std::cin >> text;

    std::string word = "Voldemort";
    std::string newWord = "You-Know-Who";

    std::string result = "";

    for (int startPos = 0; startPos < text.length(); startPos++)
    {
        bool match = true;
        for (int i = 0; i < word.length(); i++)
        {
            if (i + startPos >= text.length() || word[i] != text[i + startPos])
            {
                match = false;
                break;
            }
        }

        if (!match) result += text[startPos];
        else
        {
            result += newWord;
            startPos += word.length() - 1;
        }
    }

    std::cout << result << "\n";
    return 0;

}
