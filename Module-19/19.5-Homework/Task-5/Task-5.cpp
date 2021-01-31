#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void getQuestion(std::vector<bool>& vec, int& sector);

bool isCorrectAnswer(int number);

int main() {
  std::vector<bool> gameField(13, true);
  int expertsScore = 0, tvWatchersScore = 0;
  int currentSector = 0;

  while (expertsScore < 6 && tvWatchersScore < 6) {
    getQuestion(gameField, currentSector);

    if (isCorrectAnswer(currentSector)) {
      std::cout << "\nThis is the correct answer. Experts team gets a point!"
                << std::endl;
      ++expertsScore;
    } else {
      std::cout << "\nThis is the wrong answer. TV watchers team gets a point!"
                << std::endl;
      ++tvWatchersScore;
    }

    std::cout << "\nExperts: " << expertsScore
              << ", TV watchers: " << tvWatchersScore << std::endl
              << std::endl;
  }

  std::cout << (expertsScore == 6 ? "Experts" : "TV watchers")
            << " team is win! Congratulations!" << std::endl;
}

void getQuestion(std::vector<bool>& vec, int& sector) {
  int ofset;
  std::cout << "Let's spin the drum. Input ofset: ";
  std::cin >> ofset;
  sector = (sector + ofset) % 13;

  while (!vec[sector]) {
    ++sector;
    sector %= 13;
  }

  std::cout << "\nSector " << sector + 1 << " on the drum.\n" << std::endl;
  vec[sector] = false;

  std::ifstream question;
  question.open(".\\questions\\question" + std::to_string(sector + 1) + ".txt",
                std::ios::binary);

  if (!question.is_open()) {
    std::cerr << "File not found." << std::endl;
    std::exit(EXIT_FAILURE);
  } else {
    char buffer[100];

    while (!question.eof()) {
      question.read(buffer, sizeof(buffer) - 1);
      buffer[question.gcount()] = '\0';

      std::cout << buffer;
    }

    std::cout << std::endl;
    question.close();
  }
}

bool isCorrectAnswer(int number) {
  std::ifstream answer;
  answer.open(".\\answers\\answer" + std::to_string(number + 1) + ".txt");

  if (!answer.is_open()) {
    std::cerr << "File not found." << std::endl;
    std::exit(EXIT_FAILURE);
  } else {
    std::string tmp;
    answer >> tmp;

    std::string userInput;
    std::cout << "\nAnswer: ";
    std::cin >> userInput;

    return userInput == tmp;
  }
}

/*
Задание 5. Реализация игры «Что? Где? Когда?»
Что нужно сделать

Реализуйте простую версию интеллектуальной игры «Что? Где? Когда?».


Как происходит игра

В начале каждого хода игроки вращают волчок, то есть выбирают сектор на столе,
который сейчас играет. Всего таких секторов 13. Сектор выбирается так: с
клавиатуры вводится офсет (смещение) относительно текущего сектора на барабане.
Исходя из этого офсета вычисляется новый активный сектор, который и будет играть
в этом ходе. Если выпавший сектор уже играл, выбирает следующий неигравший за
ним. В начале всей игры стрелка установлена на первом секторе.

Как только играет какой-то из секторов, с него берётся письмо с вопросом — то
есть считывается из файла данного сектора. Вопрос показывается на экране.

После того как вопрос показан, от игрока ожидается ответ на него. Игрок вводит
этот ответ с помощью стандартного ввода. То, что он ввёл, сравнивается с
ответом, который хранится во втором файле, ассоциированном с активным сектором.
Данный файл должен содержать лишь одно слово-ответ.

Если ответ знатока-игрока был правильным, ему начисляется один балл. Если
неверен, то балл уходит телезрителям.

Игра продолжается до тех пор, пока или игрок, или зрители не наберут шесть
баллов. После этого называется победитель и программа заканчивает работу.


Что оценивается

Игра должна корректно работать от первого хода до последнего. В результате
обязательно должен выявляться победитель.
*/