#include <conio.h>

#include <fstream>
#include <iostream>

int main() {
  const int SIZE = 1000;
  int bill[]{100, 200, 500, 1000, 2000, 5000};
  int money[SIZE];

  std::ifstream moneyIn(".\\money.bin", std::ios::binary);

  if (moneyIn.is_open()) {
    moneyIn.read((char*)money, sizeof(money));
    moneyIn.close();
  } else {
    for (int i = 0; i < SIZE; ++i) {
      money[i] = 0;
    }
  }

  char mode = ' ';
  std::cout << "Select mode ('+' to fill ATM, '-' to take money)";

  while (mode != '+' && mode != '-') {
    mode = _getch();
  }

  if (mode == '+') {
    for (int i = 0; i < SIZE; ++i) {
      if (money[i] == 0) {
        money[i] = bill[std::rand() % 6];
      }
    }

    std::ofstream moneyOut(".\\money.bin", std::ios::binary);
    moneyOut.write((char*)money, sizeof(money));
    moneyOut.close();
    return EXIT_SUCCESS;
  } else if (mode == '-') {
    bool correctAmount = false;
    int amount;

    while (!correctAmount) {
      std::cout << "\nEnter the amount to withdraw: ";
      std::cin >> amount;

      if (amount % 100 == 0) {
        correctAmount = true;
      } else {
        std::cerr << "Invalid amount. Please enter again." << std::endl;
      }
    }

    int takeAmount = amount;

    for (int i = 5; i >= 0; --i) {
      for (int j = 0; j < SIZE; ++j) {
        if (money[j] == bill[i]) {
          if (takeAmount >= bill[i]) {
            money[j] = 0;
            takeAmount -= bill[i];

            if (takeAmount == 0) {
              std::cout << "Please take your money: " << amount << std::endl;

              std::ofstream moneyOut(".\\money.bin", std::ios::binary);
              moneyOut.write((char*)money, sizeof(money));
              moneyOut.close();
              return EXIT_SUCCESS;
            }
          }
        }
      }
    }

    std::cerr << "Not enough compatible bills." << std::endl;
    return EXIT_FAILURE;
  }
}

/*
Задание 4. Реализация симуляции банкомата


Что нужно сделать

Требуется реализовать упрощённую симуляцию работы банкомата. В банкомате могут
храниться только бумажные купюры номиналом от 100 до 5000 рублей. Максимально в
банкомате может храниться только 1000 купюр. Все они записываются в отдельный
файл. У банкомата, как у устройства, две основных операции — снятие денег
пользователем и наполнение деньгами инкассаторами банка.

Наполнение банкомата происходит, если при старте программы в консоль вводится
символ плюс “+”.  Количество купюр рассчитывается так, чтобы банкомат был
заполнен полностью. Все купюры при этом выбираются случайным образом.

Если на старте программы в консоль вводится минус (“-”), то симулируется снятие
пользователем денег. Пользователь указывает сумму с точностью до 100 рублей. Мы
будем считать, что каждый клиент обладает неограниченным балансом в системе и
теоретически может снять любую сумму. На практике, если данная сумма не может
быть снята из-за отсутствия подходящих денег в машине, показывается сообщение,
что эта операция невозможна.

После выполнения любой из операций программа завершает выполнение. Состояние
банкомата должно храниться в отдельном бинарном файле, автономно.


Советы и рекомендации

Вы можете хранить массив купюр целиком, помечая отсутствующие позиции нулями.


Что оценивается

Корректность работы программы симуляции банкомата. Инкассация и снятие денег
должны работать корректно.
*/