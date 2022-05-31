#include <iostream>
#include <vector>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    auto recursiveGetFileNamesByExtension =
            [](fs::path path, const std::string extension) {
                std::vector<std::string> result{};

                if (exists(path)) {
                    for (auto it : fs::recursive_directory_iterator(path)) {
                        if (it.is_regular_file() && it.path().extension().string() == extension)
                            result.push_back(it.path().filename().string());
                    }
                }
                return result;
            };

    std::cout << "Enter path: ";
    std::string path;
    std::getline(std::cin, path);
    std::cout << "Enter extension: ";
    std::string ext;
    std::getline(std::cin, ext);

    auto fileList = recursiveGetFileNamesByExtension(path, ext);

    if (fileList.empty())
        std::cout << "Nothing" << std::endl;
    else {
        for (auto it : fileList) {
            std::cout << it << std::endl;
        }
    }

    return 0;
}

//    Задание 3 (к уроку 4)
//
//
//    Цель задания
//
//    Поработать с файловой системой, используя новую библиотеку std::filesystem.
//
//
//    Что нужно сделать
//
//    В нашем арсенале теперь есть возможность рекурсивно проходить по каталогам,
//    то есть получить список всех файлов, каталогов (и подкаталогов), которые
//    содержатся по указанному пути. Для этого в стандартной библиотеке есть
//    std::filesystem::recursive_directory_iterator, принимающий на вход путь,
//    который он будет обходить рекурсивно. На каждом шаге он будет выдавать очередной путь,
//    это может быть как каталог, так и обычный файл. Например, код
//
//    for(auto& p: fs::recursive_directory_iterator("D:\\dir1"))
//    std::cout << p.path() << '\n';
//
//    выведет полные пути ко всем файлам и подкаталогам в директории D:\dir1. Вызов p.path()
//    возвращает объект типа std::filesystem::path, который позволяет:
//
//    Определить, файл это или каталог при помощи метода is_regular_file().
//    Получить расширение для обычного файла при помощи метода extension().
//
//    При помощи метода compare() можно сравнить расширение с произвольной строкой:
//    p.path().extension().compare(“.torrent”).
//
//
//    Создайте лямбда-функцию, которая принимает на вход путь в файловой системе и искомое
//    расширение в виде строки, а возвращает список имён файлов, которые имеют данное расширение().
//    Объявление нашей функции может начинаться так:
//
//    auto recursiveGetFileNamesByExtension =
//            [](std::filesystem::path path,
//               const std::string extension)