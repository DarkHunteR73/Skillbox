#include <iostream>
#include <string>

std::string encryptCaesar(int shift, std::string text)
{
    std::string result = "";
    for (int i = 0; i < text.length(); ++i)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            result += (text[i] + shift - 65) % 26 + 65;
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            result += (text[i] + shift - 97) % 26 + 97;
        }
        else result += text[i];
    }
    return result;
}

std::string decryptCaesar(int shift, std::string text)
{
    return encryptCaesar(26 - shift, text);
}

int main()
{
    std::string text;
    std::cout << "Input the text: \n";
    std::getline(std::cin, text);
    std::cout << "\nInput shift: ";
    int shift;
    std::cin >> shift;
    shift %= 26;

    std::string encrypted = encryptCaesar(shift, text);
    std::cout << "\nCipher text: \n" << encrypted << '\n';
    std::cout << "\nDecrypted text: \n" << decryptCaesar(shift, encrypted) << '\n';
}
