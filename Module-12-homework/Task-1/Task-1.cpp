#include <iostream>

int main()
{
    while (true)
    {
        std::string departureTime;

        while (true)    //Получаем строку с временем отправления
        {
            std::cout << "Input departure time in HH:MM format: ";
            std::cin >> departureTime;

            if (departureTime.length() != 5 || departureTime[2] != ':' || departureTime[0] < '0' || departureTime[0] > '9'
                || departureTime[1] < '0' || departureTime[1] > '9' || departureTime[3] < '0' || departureTime[3] > '9'
                || departureTime[4] < '0' || departureTime[4] > '9')
            {
                std::cout << "Wrong input format. Try again.\n";
                continue;
            }
            else break;
        }

        std::string arrivalTime;

        while (true)    //Получаем строку с временем прибытия
        {
            std::cout << "Input arrival time in HH:MM format: ";
            std::cin >> arrivalTime;

            if (arrivalTime.length() != 5 || arrivalTime[2] != ':' || arrivalTime[0] < '0' || arrivalTime[0] > '9'
                || arrivalTime[1] < '0' || arrivalTime[1] > '9' || arrivalTime[3] < '0' || arrivalTime[3] > '9'
                || arrivalTime[4] < '0' || arrivalTime[4] > '9')
            {
                std::cout << "Wrong input format. Try again.\n";
                continue;
            }
            else break;
        }
        
        int depHours = (departureTime[0] - '0') * 10 + (departureTime[1] - '0');
        int depMinutes = (departureTime[3] - '0') * 10 + (departureTime[4] - '0');
        int arrHours = (arrivalTime[0] - '0') * 10 + (arrivalTime[1] - '0');
        int arrMinutes = (arrivalTime[3] - '0') * 10 + (arrivalTime[4] - '0');

        if (depHours > 23 || arrHours > 23 || depMinutes > 59 || arrMinutes > 59)
        {
            std::cout << "Wrong input. Try again.\n";
            continue;
        }
        else
        {
            int depTimeMinutes = depHours * 60 + depMinutes;
            int arrTimeMinutes = arrHours * 60 + arrMinutes;
            int travelTime;

            if (depTimeMinutes < arrTimeMinutes)
            {
                travelTime = depTimeMinutes - arrTimeMinutes;
            }
            else 
            {
                travelTime = (1440 - depTimeMinutes) + arrTimeMinutes;
            }
            std::cout << "Travel time: " << travelTime / 60 << " hours " << travelTime % 60 << " minutes.\n";
            break;
        }
    }
    return 0;
}
/*
1. Время в пути

    Поезд отправляется в AA часов BB минут и прибывает в пункт назначения в CC часов DD минут. Сколько часов и минут он 
находится в пути?

    Напишите программу, которая принимает от пользователя две строки — время отправления и время прибытия поезда.
Время задается строкой из 5 символов в формате HH:MM. Обеспечьте контроль ввода, проверьте также, что время корректно.

    Программа должна ответить, сколько часов и минут поезд находится в пути. Если время отправления больше времени 
прибытия, считайте, что поезд прибывает в пункт назначения на следующий день.


Примеры:

Введите время отправления: 07:15

Введите время прибытия: 16:55

Поезд находится в пути 9 часов 40 минут


Введите время отправления: 21:10

Введите время прибытия: 08:05

Поезд находится в пути 10 часов 55 минут
*/