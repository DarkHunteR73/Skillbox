#include <iostream>
#include <vector>

void removeFromPosition(std::vector<int>& vec, int& index)
{
    for (int i = index; i < vec.size() - 1; ++i)
    {
        vec[i] = vec[i + 1];
    }
    vec.pop_back();
}

int main()
{
    int n = 0;
    std::cout << "How many numbers do you want to enter? ";
    std::cin >> n;

    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> vec[i];
    }

    std::cout << "\nEnter the value you want to delete: ";
    int val;
    std::cin >> val;

    for (int i = 0; i < vec.size(); ++i)
    {
        if (vec[i] == val)
        {
            removeFromPosition(vec, i);
            --i;
        }
        else std::cout << vec[i] << ' ';
    }

    if (vec.empty())
    {
        std::cout << "\nVector is empty." << std::endl;
    }

    std::cin.clear();
    std::cin.ignore(32767, '\n');
    std::cin.get();
}

//Задача 1.
//
//Пользователь вводит с клавиатуры число n, далее -- n целых чисел, которые нужно записать в вектор.
//
//Потом пользователь вводит ещё одно значение.Нужно удалить из вектора все элементы, которые равны данному значению, и вывести итоговое состояние вектора
//
//Пример :
//
//Пользователь ввёл 5, потом числа 1, 3, 3, 5, 1. И потом -- число 3. Необходимо, чтобы в векторе остались числа 1, 5, 1, которые надо вывести их на экран.