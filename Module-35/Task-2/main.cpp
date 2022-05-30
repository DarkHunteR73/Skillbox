#include <iostream>
#include <unordered_set>
#include <vector>
#include <memory>

int main() {
    auto removeDuplicateNums = [](std::vector<int> nums) {
        if (nums.empty())
            return std::unique_ptr<std::vector<int>>{};

        std::unordered_set<int> numset{ nums.begin(), nums.end() };

        std::vector<int> result;
        for (auto i : numset) {
            result.push_back(i);
        }
        return std::make_unique<std::vector<int>>(result);
    };

    std::vector<int> v{ 12, 3, 5, 12, 3, 1, 5, 3 };
    auto result = removeDuplicateNums(v);

    for (auto i : *result) {
        std::cout << i << ' ';
    }

    return 0;
}

//    Задание 2 (урок 3)
//
//
//    Цель задания
//
//    Поработать с новыми структурами данных.
//
//
//    Что нужно сделать
//
//    Так как std::unordered_set позволяет нам быстро определять, есть ли указанный ключ в контейнере,
//    мы можем использовать его для фильтрации уникальных чисел.
//
//    Создайте лямбда-выражение, принимающее на вход std::vector<int>, в котором содержатся числа,
//    которые могут повторяться. Внутри лямбды создайте unordered_set и при помощи него определяйте,
//    сколько раз текущее число вам встречалось раньше. В результате верните std::unique_ptr<std::vector<int>>,
//    содержащий числа без повторов. При проходе по контейнеру используйте новый формат цикла for и
//    ключевое слово auto.