#include <iostream>
#include <vector>

// Удаляем элемент из указанного индекса
void removeFromPosition(std::vector<int>& vec, int& index)
{
    if (index == vec.size() - 1) vec.resize(vec.size() - 1);
    else
    {
        for (int i = index; i < vec.size() - 1; ++i)
        {
            vec[i] = vec[i + 1];
        }
        vec.resize(vec.size() - 1);
    }
}

// Выводим содержимое вектора на экран
void printVector(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << ' ';
    }
}

int main()
{
    std::vector<int> showcase{ 1,5,35,19,256,89,23,100,50,42,341,167,2 };
    int numberOfRequests;
    std::cout << "Enter the number of requests: ";
    std::cin >> numberOfRequests;

    for (int i = 0; i < numberOfRequests; )
    {
        int mode, num;

        std::cout << "Enter your request " << i + 1 << ": ";
        std::cin >> mode >> num;

        switch (mode)
        {
        case 1:
        {
            showcase.resize(showcase.size() + 1);
            showcase[showcase.size() - 1] = num;
            ++i;
            break;
        }
        case 2:
        {
            if (num < showcase.size())
            {
                removeFromPosition(showcase, num);
                ++i;
            }
            else
            {
                std::cerr << "Error! Wrong index" << std::endl;
            }
            break;
        }
        default: std::cerr << "Error! Wrong request" << std::endl;
        }
    }
    std::cout << std::endl;
    printVector(showcase);
}

//Задание 2
//Представим, что роботов могут не только покупать, забирая с витрины, но и “выставлять” в конец витрины.Пусть с клавиатуры вводят число K,
//а потом -- K запросов вида “1 n” и “2 m”.Запрос вида “1 n” означает, что в конец витрины поставили робота номер n.Запроc “2 m” означает, 
//что из витрины забрали робота по индексу m.Необходимо смоделировать такое взаимодействие и после проведения всех запросов вывести на экран
//оставшихся на витрине роботов.