#include <iostream>

int at_indexFind(std::string adress) // Ищет '@'
{
    for (int i = 0; i < adress.length(); ++i)
    {
        if (adress[i] == '@') return i;
    }
    return -1;
}

bool symbol_check(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')
        || (ch >= '0' && ch <= '9') || ch == '.' || ch == '-')
    {
        return true;
    }
    else return false;
}

bool localPart_validation(std::string adress, int at_index)   // Проверяет левую часть адреса до '@'
{
    std::string localPart_valid_chars = "!#$%&'*+/=?^_`{|}~";
    if (at_index < 1 || at_index > 64 || adress[0] == '.' || adress[at_index - 1] == '.') return false;
    else
    {
        for (int i = 0; i < at_index; ++i)
        {
            if (adress[i] == '.' && adress[i + 1] == '.') return false; // Ищет две точки подряд

            if (symbol_check(adress[i])) continue;
            else
            {
                bool match = false;
                for (int j = 0; j < localPart_valid_chars.length() && !match; ++j)
                {
                    if (adress[i] == localPart_valid_chars[j]) match = true;
                }
                if (!match) return false;
            }
        }
        return true;
    }
}

bool domainName_validation(std::string adress, int at_index)   // Проверяет правую часть адреса после '@'
{
    if (at_index < 1 || adress.length() - at_index > 63 || adress[adress.length()-1] == '.' 
        || adress[at_index + 1] == '.')
    {
        return false;
    }
    else
    {
        for (int i = at_index + 1; i < adress.length(); ++i)
        {
            if (adress[i] == '.' && adress[i + 1] == '.') return false; // Ищет две точки подряд

            if (symbol_check(adress[i])) continue;
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
    int at_index = at_indexFind(email);
    std::cout << (localPart_validation(email, at_index) && domainName_validation(email, at_index) ? "Yes" : "No") << '\n';
}