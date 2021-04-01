#include <iostream>
#include <vector>

int main()
{
    std::cout << "How many elements do you want? ";
    int N;
    std::cin >> N;

    std::vector<int>vec(N);
    for (int i = 0; i < N; ++i)
    {
        std::cout << i + 1 << ".: ";
        std::cin >> vec[i];
    }

    int max = vec[0], secondMax = vec[0];
    for (int i = 0; i < N; ++i)
    {
        if (vec[i] > max) max = vec[i];
        else if (vec[i] > secondMax && vec[i] < max) secondMax = vec[i];
    }

    std::cout << '\n' << secondMax;
}

//Задание 3
//Пользователь вводит с клавиатуры число n, а затем -- n целых чисел.Необходимо отыскать второе по величине из этих чисел и вывести на экран.