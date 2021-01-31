#include <iostream>
#include <map>
#include <string>

std::map<char, int> strToMap(const std::string& str) {
  std::map<char, int> map;

  for (int i = 0; i < str.length(); ++i) {
    if (map.contains(str[i])) {
      ++map[str[i]];
    } else {
      map.insert(std::make_pair(str[i], 1));
    }
  }

  return map;
}

int main() {
  std::string str1, str2;

  std::cout << "Input two words: ";
  std::cin >> str1 >> str2;

  std::cout << (strToMap(str1) == strToMap(str2)
                    ? "These words are anagrams"
                    : "These words are not anagrams")
            << std::endl;
}

//Задание 3. Анаграммы
//
//
//Что нужно сделать
//
//Напишите функцию, которая принимает две строки и возвращает true, если первая
//строка является анаграммой второй(то есть можно получить
//  первую строку из второй путём перестановки букв местами), и false иначе.
// Для достижения хорошей асимптотики решения рекомендуется использовать
// std::map.
//
//Пример анаграммы : лекарство — стекловар
//
//
//Чек - лист для проверки задачи
//
//Функция принимает корректные типы данных, тип возвращаемого значения — bool.
//Функция не использует библиотек, кроме <iostream>, <map>, <string>.
//Функция корректно определяет, являются ли строки анаграммами.