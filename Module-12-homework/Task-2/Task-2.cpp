#include <iostream>
#include <iomanip>

int main()
{
    std::string guessNumber;
    std::string secondNumber;

    bool correct = false;
    while (!correct)
    {
        std::cout << std::setw(21) << "Input guess four-digit number: ";
        std::cin >> guessNumber;

        std::cout << std::setw(21) << "Input second four-digit number: ";
        std::cin >> secondNumber;

        if (guessNumber.length()!=4||secondNumber.length()!=4)
        {
            std::cout << "Wrong number length. Try again.\n";
            continue;
        }
        
        for (int i = 0; i < 4; ++i)
        {
            if (guessNumber[i] < '0' || secondNumber[i] < '0' || guessNumber[i] > '9' || secondNumber[i] > '9')
            {
                std::cout << "Only numbers are allowed. Try again.\n";
                break;
            }
            else correct = true;
        }
    }

    int bulls = 0, cows = 0;
    for (int i = 0; i < guessNumber.length(); ++i)
    {
        if (guessNumber[i] == secondNumber[i])
        {
            ++bulls;
            guessNumber[i] = 'B';
            secondNumber[i] = 'B';
        }
    }

    for (int i = 0; i < guessNumber.length(); ++i)
    {
        if (guessNumber[i] == 'B') continue;
        else
        {
            for (int j = 0; j < secondNumber.length(); ++j)
            {
                if (guessNumber[i] == secondNumber[j])
                {
                    ++cows;
                    guessNumber[i] = 'C';
                    secondNumber[j] = 'C';
                    break;
                }
            }
        }
    }

    std::cout << "Bulls: " << bulls << ", cows: " << cows << ".\n";
    return 0;
}
/*
2. Быки и коровы

    В логической игре “быки и коровы” первый игрок загадывает четырехзначное число (оно может начинаться и с нулей),
а второй игрок должен его отгадать. Отгадывание происходит так: своим ходом второй игрок называет любое четырехзначное
число, а первый ему отвечает, сколько в этом числе “быков” и сколько “коров”. Корова — это цифра, которая совпадает по
значению с какой-то из цифр задуманного числа, но стоит не на нужном месте. Бык — это цифра, совпадающая с цифрой в 
задуманном числе и по значению, и по расположению.

    Вам нужно написать программу, которая по загаданному числу и по названному вторым игроком числу определяет,
сколько во втором числе “быков” и сколько “коров”. Не забудьте, что числа могут начинаться с нулей!

Примечание. Сумма быков и коров не может быть больше 4.


Примеры:

Введите задуманное число: 5671

Введите второе число: 7251

Быков: 1, коров: 2


Введите задуманное число: 1234

Введите второе число: 1234

Быков: 4, коров: 0


Введите задуманное число: 0023

Введите второе число: 2013

Быков: 2, коров: 1


Введите задуманное число: 1111

Введите второе число: 1111

Быков: 4, коров: 0
*/