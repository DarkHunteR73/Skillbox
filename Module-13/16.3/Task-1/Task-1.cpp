#include <iostream>
#include <vector>

// Удаляем элемент из указанного индекса
void removeFromPosition(std::vector<int> &vec, int &index)
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
void printVector(std::vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << ' ';
    }
}

int main()
{
    // Определяем размер вектора
    std::cout << "Input the number of robots: ";
    int n;
    std::cin >> n;

    // Создаём вектор заданного размера
    std::vector<int> showcase(n);

    // Забиваем вектор номерами
    for (int i = 0; i < showcase.size(); ++i)
    {
        std::cout << "Input the number: ";
        std::cin >> showcase[i];
    }

    printVector(showcase);

    std::cout << "\nHow many robots will we remove? ";
    int m = 0;
    std::cin >> m;
    if (m < n)
    {
        for (int i = 0; i < m;)
        {
            std::cout << "\nWhich robot will we remove? ";
            int index;
            std::cin >> index;
            if (index < showcase.size())
            {
                removeFromPosition(showcase, index);
                printVector(showcase);
                ++i;
            }
            else std::cerr << "Error! Wrong index" << std::endl;
        }
    }
    else if (m == n)
    {
        std::cout << "\nAll robots removed" << std::endl;
        showcase.clear();
    }
    else std::cerr << "Error! We cannot remove more robots than we have" << std::endl;
}

//Задание 1
//На витрине стоят несколько роботов, у каждого есть свой номер.Они задаются с клавиатуры(сначала вводится число n, потом -- n номеров роботов).
//Далее вводится число m и после этого -- m индексов(от 0 до количества оставшихся роботов на витрине).Когда введён очередной индекс -- робота покупают,
//то есть он покидает витрину, а остальные роботы “группируются”, смещаясь на один шаг назад.Необходимо вывести список оставшихся, после всех покупок, роботов.
//
//Пример: на витрине стояли роботы{ 100, 200, 250, 300 }. Сначала забрали робота с индексом 1, то есть с номером 200, осталось{ 100,250,300 }.
//Потом забрали робота с индексом 1, то есть с номером 250, осталось{ 100,300 }