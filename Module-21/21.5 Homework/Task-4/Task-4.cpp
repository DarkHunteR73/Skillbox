#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

struct Character {
  std::string name = "Unknown";
  int health = 0;
  int armor = 0;
  int damage = 0;
  bool player = false;

  struct Position {
    int x = 0;
    int y = 0;
  } position;
};

//Вывод поля на экран
void printField(char field[][40], Character character[]);

//Начало новой игры
void initGame(Character character[]);

//Сохранение
void saveGame(Character character[]);

//Загрузка
void loadGame(Character character[]);

//Проверка окончания игры
bool endGame(Character character[]);

//Следующий ход
void nextTurn(Character character[]);

//Получение числа в заданном диапазоне
int getValue(int minValue, int maxValue, std::string msg);

//Проверка соседней клетки в направлении хода. Возвращает индекс массива
//персонажа, если клетка занята. Возвращает -1, если клетка свободна
int isCellBusy(Character character[], int tmpX, int tmpY);

void takeDamage(Character& character, int _damage);

int main() {
  std::srand(std::time(nullptr));
  char field[40][40];

  Character character[6];

  initGame(character);

  while (!endGame(character)) {
    printField(field, character);
    nextTurn(character);
  }
}

void printField(char field[][40], Character character[]) {
  for (int i = 0; i < 40; ++i) {
    for (int j = 0; j < 40; ++j) {
      field[i][j] = '.';
    }
  }

  field[character[0].position.y][character[0].position.x] = 'P';

  for (int i = 1; i < 6; ++i) {
    if (character[i].health > 0) {
      field[character[i].position.y][character[i].position.x] = 'E';
    }
  }

  for (int i = 0; i < 40; ++i) {
    for (int j = 0; j < 40; ++j) {
      std::cout << field[i][j];
    }
    std::cout << std::endl;
  }
}

void initGame(Character character[]) {
  std::cout << "Enter your nickname: ";
  std::cin >> character[0].name;

  character[0].health = getValue(1, 200, "Health");
  character[0].armor = getValue(0, 100, "Armor");
  character[0].damage = getValue(15, 100, "Damage");
  character[0].player = true;
  character[0].position.x = std::rand() % 40;
  character[0].position.y = std::rand() % 40;

  for (int i = 1; i < 6; ++i) {
    character[i].name = "Enemy #" + std::to_string(i);
    character[i].health = std::rand() % 101 + 50;
    character[i].armor = std::rand() % 51;
    character[i].damage = std::rand() % 16 + 15;
    character[i].position.x = std::rand() % 40;
    character[i].position.y = std::rand() % 40;
  }
}

void saveGame(Character character[]) {
  std::ofstream file("save.bin", std::ios::binary);

  file.clear();

  for (int i = 0; i < 6; ++i) {
    int len = character[i].name.length();
    file.write((char*)&len, sizeof(len));
    file.write(character[i].name.c_str(), len);
    file.write((char*)&character[i].health, sizeof(character[i].health));
    file.write((char*)&character[i].armor, sizeof(character[i].armor));
    file.write((char*)&character[i].damage, sizeof(character[i].damage));
    file.write((char*)&character[i].player, sizeof(character[i].player));
    file.write((char*)&character[i].position.x,
               sizeof(character[i].position.x));
    file.write((char*)&character[i].position.y,
               sizeof(character[i].position.y));
  }

  file.close();
  std::cout << "\nGame saved." << std::endl;
}

void loadGame(Character character[]) {
  std::ifstream file("save.bin", std::ios::binary);

  if (file.is_open()) {
    for (int i = 0; i < 6; ++i) {
      int len;
      file.read((char*)&len, sizeof(len));
      character[i].name.resize(len);
      file.read((char*)character[i].name.c_str(), len);
      file.read((char*)&character[i].health, sizeof(character[i].health));
      file.read((char*)&character[i].armor, sizeof(character[i].armor));
      file.read((char*)&character[i].damage, sizeof(character[i].damage));
      file.read((char*)&character[i].player, sizeof(character[i].player));
      file.read((char*)&character[i].position.x,
                sizeof(character[i].position.x));
      file.read((char*)&character[i].position.y,
                sizeof(character[i].position.y));
    }

    file.close();
    std::cout << "\nGame loaded." << std::endl;
  } else {
    std::cerr << "\nNo saved games." << std::endl;
  }
}

bool endGame(Character character[]) {
  if (character[0].health == 0) {
    std::cout << "\nGame over! You died..." << std::endl;
    return true;
  }

  int aliveEnemyCount = 0;

  for (int i = 1; i < 6; ++i) {
    if (character[i].health > 0) {
      ++aliveEnemyCount;
    }
  }

  if (aliveEnemyCount == 0) {
    std::cout << "\nAll enemies are died. You win!" << std::endl;
    return true;
  } else
    return false;
}

void nextTurn(Character character[]) {
  for (int i = 0; i < 6; ++i) {
    int tmpX = character[i].position.x;
    int tmpY = character[i].position.y;

    if (character[i].player) {
      bool makeTurn;

      do {
        makeTurn = false;

        std::cout << "Command: ";
        std::string command;
        std::cin >> command;

        if (command == "save") {
          saveGame(character);
        } else if (command == "load") {
          loadGame(character);
        } else {
          if (command == "top") {
            --tmpY;
            makeTurn = true;
          } else if (command == "bottom") {
            ++tmpY;
            makeTurn = true;
          } else if (command == "left") {
            --tmpX;
            makeTurn = true;
          } else if (command == "right") {
            ++tmpX;
            makeTurn = true;
          } else {
            std::cout << "\nUnknown command!" << std::endl;
          }
        }
      } while (!makeTurn);
    } else {
      if (character[i].health > 0) {
        int direction = 0 + std::rand() % 2;

        if (direction == 0) {
          direction = 0 + std::rand() % 2;
          if (direction == 0) --direction;

          tmpX += direction;
        } else {
          direction = 0 + std::rand() % 2;
          if (direction == 0) --direction;

          tmpY += direction;
        }
      }
    }

    if (tmpX >= 0 && tmpX < 40 && tmpY >= 0 && tmpY < 40) {
      int target = isCellBusy(character, tmpX, tmpY);

      if (target < 0) {
        character[i].position.x = tmpX;
        character[i].position.y = tmpY;
      } else {
        if (character[i].player != character[target].player) {
          std::cout << '\n'
                    << character[i].name << " deals " << character[i].damage
                    << " damage to the " << character[target].name << ". ";
          takeDamage(character[target], character[i].damage);
        }
      }
    }
  }
}

void takeDamage(Character& character, int _damage) {
  character.armor -= _damage;

  if (character.armor < 0) {
    character.health += character.armor;
    character.armor = 0;
  }

  if (character.health <= 0) {
    character.health = 0;
    character.position.x = -999;
    character.position.y = -999;

    std::cout << character.name << " dies." << std::endl;
  } else {
    std::cout << std::endl;
  }
}

int isCellBusy(Character character[], int tmpX, int tmpY) {
  for (int i = 0; i < 6; ++i) {
    if (character[i].position.x == tmpX && character[i].position.y == tmpY) {
      return i;
    }
  }

  return -1;
}

int getValue(int minValue, int maxValue, std::string msg = "Enter value") {
  int num;

  while (true) {
    std::cout << msg << '(' << minValue << '-' << maxValue << "): ";
    std::cin >> num;

    if (num >= minValue && num <= maxValue) {
      return num;
    } else {
      std::cerr << "Wrong value! Please try again" << std::endl;
    }
  }
}

/*
Задание 4. Реализация ролевой пошаговой игры


Что нужно сделать

Реализуйте сильно упрощённую версию ролевой пошаговой игры:

Игра происходит на карте размером 40 на 40 клеток. По клеткам перемещаются враги
и персонаж игрока.

После каждого хода игрока карта показывается вновь со всеми врагами на ней.
Игрок помечается буквой P. Враги буквой E. Пустые места — точкой.

Каждый персонаж игры представлен в виде структуры с полями: имя, жизни, броня,
урон.

Вначале игры создаются 5 случайных врагов в случайных клетках карты. Имена
врагам задаются в формате “Enemy #N”, где N — это порядковый номер врага.
Уровень жизней врагам задаётся случайно, от 50 до 150. Уровень брони варьируется
от 0 до 50. Урон тоже выбирается случайно от 15 до 30 единиц.

Игрок конструирует своего персонажа самостоятельно. Задаёт все его параметры,
включая имя.

Все персонажи появляются в случайных местах карты.

Игрок осуществляет ход с помощью команд: left, right, top, bottom. В зависимости
от команды и выбирается направление перемещения персонажа: влево, вправо, вверх,
вниз.

Враги перемещаются в случайном направлении.

Если персонаж (враг или игрок) перемещается в сторону, где уже находится
какой-то персонаж, то он бьёт этого персонажа с помощью своего урона. Враги при
этом никогда не бьют врагов, а просто пропускают ход и остаются на своём месте.
За пределы карты (40 на 40 клеток) ходить нельзя никому. Если кто-то выбрал
направление за гранью дозволенного, ход пропускается.

Формула для расчёта урона совпадает с той, что была в самом уроке. Жизни
уменьшаются на оставшийся после брони урон. При этом сама броня тоже сокращается
на приведённый урон.

Игра заканчивается тогда, когда либо умирают все враги, либо персонаж игрока. В
первом случае на экран выводится сообщение о поражении, во втором — победа.

Если в начале хода игрок вводит команду save или load вместо направления
перемещения, то игра либо делает сохранение своего состояния в файл, либо
загружает это состояние из файла соответственно.


Советы и рекомендации

Для определения команды персонажа можно завести специальный флаг внутри
структуры данных персонажа.

Для отображения координат персонажей можете использовать структуру вектора из
другой задачи, но заменить типы координат.
*/