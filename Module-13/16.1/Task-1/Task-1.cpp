#include <iostream>
#include <vector>

int main()
{
    std::cout << "How many elements do you want? ";
    int N;
    std::cin >> N;

    std::vector<int>vec(N);
    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
        std::cout << i + 1 << ". ";
        std::cin >> vec[i];
        sum += vec[i];
    }

    std::cout << "Average number is: " << static_cast<float>(sum) / N;
}

//Задание 1
//Пользователь вводит с клавиатуры число n, а затем -- n целых чисел.
//Необходимо вычислить их среднее арифметическое и вывести на экран.