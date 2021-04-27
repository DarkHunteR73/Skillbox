#include <iostream>
#include <vector>

int main()
{
    std::cout << "How many elements do you want? ";
    int N;
    std::cin >> N;

    std::vector<float>vec(N);
    for (int i = 0; i < N; ++i)
    {
        std::cout << i + 1 << ".: ";
        std::cin >> vec[N - i - 1];
    }

    std::cout << std::endl;

    //for (int i = 0; i < N / 2; ++i)
    //{
    //    std::swap(vec[i], vec[N - i - 1]);
    //}

    for (int i = 0; i < N; ++i)
    {
        std::cout << i + 1 << ". " << vec[i] << std::endl;
    }
}

//Задание 2
//Пользователь вводит с клавиатуры число n, а затем -- n действительных(дробных) чисел.Необходимо вывести их все в обратном порядке(то есть сначала то число,
//которые пользователь ввёл последним и так далее).