#include <conio.h>

#include <fstream>
#include <iostream>

int main() {
  std::ifstream river(".\\river.txt");
  int count = 0;

  if (!river.is_open()) {
    std::cerr << "File not found!" << std::endl;
    return EXIT_FAILURE;
  } else {
    std::ofstream basket(".\\basket.txt", std::ios::app);

    while (true) {
      std::string userInput;
      std::cout << "What kind of fish are you going to fish?" << std::endl;
      std::cin >> userInput;

      while (!river.eof()) {
        std::string tmp;
        river >> tmp;

        if (tmp == userInput) {
          std::cout << "You caught: " << tmp << std::endl;
          basket << userInput << std::endl;
          ++count;
          break;
        } else if (river.eof() && tmp != userInput) {
          std::cout << "You didn't catch anything" << std::endl;
        }
      }

      char ch = ' ';
      while (ch != 'y' && ch != 'n') {
        std::cout << "Do you want to continue? (y/n)" << std::endl;

        ch = _getch();

        if (ch == 'n') {
          std::cout << "Fishing is over. Fish caught: " << count << std::endl;
          river.close();
          basket.close();
          return EXIT_SUCCESS;
        }
      }

      river.seekg(0);
    }
  }
}

/*
Задание 3. Реализация симуляции игры «Рыбалка»


Что нужно сделать

Реализуйте простую симуляцию игры в рыбалку. В исходном текстовом файле реки
(river.txt) задаётся список из видов рыб, которые можно в ней поймать. Рыбок
может быть сколько угодно, разных видов. Виды при этом могут повторяться.

В начале программы пользователь указывает, какую именно рыбу он сейчас будет
ловить — вид этой рыбы. После этого из первого файла друг за другом
осуществляется чтение его содержимого, вид за видом. Если на отдельных шагах вид
совпал с указанным пользователем, в выходной файл basket.txt (корзинка)
записывается этот вид.

В конце программы показывается, сколько было поймано рыб за текущую ловлю.
Программу можно запускать несколько раз, при этом уже пойманные рыбы должны
сохраняться в файле-корзинке.


Пример содержания исходного файла

sunfish
shad
carp
bass
bullhead
carp
walleye
catfish
carp


Что оценивается

Корректность работы программы симуляции игры в рыбалку. Пойманные рыбы должны
записываться в выходной файл.
*/