#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    std::string username, answer;
    std::cout << "Как тебя зовут? ";
    std::getline(std::cin, username);
    std::cout << username << ", купи слона.\n>>>";
    std::getline(std::cin, answer);

    while (1<2)
    {
        std::cout << "Все говорят " << answer << ", а ты купи слона.\n>>>";
        std::getline(std::cin, answer);
    }
    return 0;
}