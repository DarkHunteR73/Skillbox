#include <iostream>
#include <string>

bool symbolCheck(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')
        || (ch >= '0' && ch <= '9') || ch == '.' || ch == '-')
    {
        return true;
    }
    else return false;
}

bool localPartValidation(std::string adress, int atIndex)   // Проверяет левую часть адреса до '@'
{
    std::string localPartValidChars = "!#$%&'*+/=?^_`{|}~";
    if (atIndex < 1 || atIndex > 64 || adress[0] == '.' || adress[atIndex - 1] == '.') return false;
    else
    {
        for (int i = 0; i < atIndex; ++i)
        {
            if (adress[i] == '.' && adress[i + 1] == '.') return false; // Ищет две точки подряд

            if (symbolCheck(adress[i])) continue;
            else
            {
                bool match = false;
                for (int j = 0; j < localPartValidChars.length() && !match; ++j)
                {
                    if (adress[i] == localPartValidChars[j]) match = true;
                }
                if (!match) return false;
            }
        }
        return true;
    }
}

bool domainNameValidation(std::string adress, int atIndex)   // Проверяет правую часть адреса после '@'
{
    if (atIndex < 1 || adress.length() - atIndex > 63 || adress[adress.length()-1] == '.' 
        || adress[atIndex + 1] == '.')
    {
        return false;
    }
    else
    {
        for (int i = atIndex + 1; i < adress.length(); ++i)
        {
            if (adress[i] == '.' && adress[i + 1] == '.') return false; // Ищет две точки подряд

            if (symbolCheck(adress[i])) continue;
            else return false;
        }
        return true;
    }
}

int main()
{
    std::cout << "Input email adress: ";
    std::string email;
    std::cin >> email;
    int atIndex = email.find('@');
    std::cout << (localPartValidation(email, atIndex) && domainNameValidation(email, atIndex) ? "Yes" : "No") << '\n';
}