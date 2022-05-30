#include <iostream>
#include <vector>

void print(std::initializer_list<int> list) {
    std::vector<int> vec{ list };

    for (auto i : vec) {
        std::cout << i << ' ';
    }
}

int main() {
    print({ 1, 2, 3, 4, 5 });
    return 0;
}

//    Задание 1 (к уроку 2)
//
//
//    Цель задания
//
//    Закрепить работу с нововведениями в базовых конструкциях языка.
//
//
//    Что нужно сделать
//
//    Вспомните пример с range-based циклом по закрытию файлов:
//
//    for(auto& File : files)
//    currentFile.close();
//
//    По аналогии распечатайте числа от 1 до 5, используя auto и initializer_list.
