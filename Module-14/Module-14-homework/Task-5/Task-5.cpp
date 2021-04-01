#include <iostream>

bool isCorrect(std::string number)
{
    bool dot = false;

    int dotPosition = 0;
    for (int i = 0; !dot && i < number.length(); ++i)  // Поиск десятичной точки
    {
        if (number[i] == '.')
        {
            dot = true;
            dotPosition = i;
        }
    }

    int digits = 0;
    for (int j = 0; j < number.length(); ++j) // Проверка символов
    {
        if (number[0] == '-' && j == 0) continue; 
        if (dot && j == dotPosition) continue;

        if (number[j] >= '0' && number[j] <= '9') ++digits;
        else return false;
    }
    return digits > 0;
}

bool trueMinus(std::string number)      //Для устранения разницы между -0 и 0 и т.п.
{
    if (number[0] == '-')
    {
        for (int i = 1; i < number.length(); ++i)
        {
            if (number[i] != '0' && number[i] != '.') return true;
        }
    }
    return false;
}

int dotFind(std::string number) //Если точки нет, то присваиваем индекс конца строки
{
    int dot = number.length();
    for (int i = 0; i < number.length(); ++i)
    {
        if (number[i] == '.') return i;
    }
    return dot;
}

std::string prepareNumber(std::string number) //Убираем лишнее (бессмысленные нули и знак минус) 
{
    int startPos = 0;
    std::string preparedNumber = "";
    bool minus = trueMinus(number);
    if (number[0] == '-' && minus)
    {
        ++startPos;
        preparedNumber += '-';
    }
    else if (number[0] == '-' && !minus)
    {
        number[0] = '0';
    }

    int dot = dotFind(number);
    bool prefixZero = true;
    for (int i = startPos; i < dot; i++)
    {
        if (prefixZero && number[i] == '0') continue;
        else
        {
            prefixZero = false;
            preparedNumber += number[i];
        }
    }

    int rFindIndex = number.length() - 1;
    for (int i = rFindIndex; i >= dot; --i)
    {
        if (number[i] != '0')
        {
            rFindIndex = i;
            break;
        }
    }

    if (dot != rFindIndex)
    {
        for (int i = dot; i <= rFindIndex; ++i)
        {
            preparedNumber += number[i];
        }
    }

    return preparedNumber;
}

std::string getPartOfNumber(std::string number, int left, int right)
{
    std::string tmp = "";
    for (int i = left; i < right; ++i)
    {
        tmp += number[i];
    }
    return tmp;
}

bool getNumberComparsion(std::string number1, std::string number2)
{
    std::string num1IntPart = getPartOfNumber(number1, 0, dotFind(number1));
    std::string num2IntPart = getPartOfNumber(number2, 0, dotFind(number2));

    if (num1IntPart.length() != num2IntPart.length())
    {
        return num1IntPart.length() < num2IntPart.length();
    }
    else
    {
        if (num1IntPart != num2IntPart)
        {
            return num1IntPart < num2IntPart;
        }
        else
        {
            std::string num1FracPart = getPartOfNumber(number1, dotFind(number1), number1.length());
            std::string num2FracPart = getPartOfNumber(number2, dotFind(number2), number2.length());

            return num1FracPart < num2FracPart;
        }
    }
}

std::string getResult(std::string number1, std::string number2)
{
    number1 = prepareNumber(number1);
    number2 = prepareNumber(number2);

    if (number1 == number2) return "Equal";
    if (number1[0] == '-' && number2[0] != '-') return "Less";
    if (number1[0] != '-' && number2[0] == '-') return "More";

    if (number1[0] != '-' && number2[0] != '-')
    {
        return (getNumberComparsion(number1, number2) ? "Less" : "More");
    }
    else
    {
        return (getNumberComparsion(number1, number2) ? "More" : "Less");
    }
}

int main()
{
    std::cout << "Input the first number: ";
    std::string number1;
    std::cin >> number1;

    std::cout << "Input the second number: ";
    std::string number2;
    std::cin >> number2;

    if (isCorrect(number1) && isCorrect(number2))
    {
        std::cout << getResult(number1, number2);
    }
    else std::cout << "Error\n";
}

/*
Задание 5. Сравнение длинных вещественных чисел


Что нужно сделать

    Вы продолжаете писать калькулятор, работающий над вещественными числами повышенной точности. Вы уже научились
проверять корректность записи вещественных чисел в виде строк, и теперь перед вами новая цель — научиться сравнивать
такие вещественные числа.

    Пользователь вводит две строки, задающие вещественные числа, в том же формате, как было описано в задаче
«Длинное вещественное число». Программа должна проверить корректность ввода (для этого можно переиспользовать код,
написанный в задаче «Длинное вещественное число»), после чего вывести слово Less, если первое число строго меньше второго;
слово More, если первое число строго больше второго; и слово Equal, если введённые числа равны.


Примеры:

Ввод: 2.39 3.61
Ответ: Less


Ввод: 0123 12.3
Ответ: More
Ввод: 12345678 12345678.00
Ответ: Equal


Ввод: -1.0 1.0
Ответ: Less


Советы и рекомендации

    Активно используйте оператор индексации строки str[i], но помните что индексы начинаются с нуля, а не с единицы.
    Создайте отдельную функцию для получения целой и дробной частей числа. Её можно сделать на основе задачи об IP-адресах,
    т.к. там тоже использовалась точка в качестве разделителя.
    Для сравнения дробных частей можно создать специальную функцию безопасного доступа к символу строки по индексу.
    Для дробных чисел, если этот индекс больше длины дробной части, данная функция может безопасно вернуть 0.


Что оценивается

Программа должна выдавать корректные результаты сравнениях двух длинных вещественных чисел.
*/