#include <iostream>

// Вывод игрового поля на экран
void printGameField(char gamefieldArray[][3])
{
	system("cls");
	std::cout << "-------------" << std::endl;
	std::cout << "|   |   |   |" << std::endl;
	std::cout << "| " << gamefieldArray[0][0] << " | " << gamefieldArray[0][1] << " | " << gamefieldArray[0][2] << " |" << std::endl;
	std::cout << "|   |   |   |" << std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << "|   |   |   |" << std::endl;
	std::cout << "| " << gamefieldArray[1][0] << " | " << gamefieldArray[1][1] << " | " << gamefieldArray[1][2] << " |" << std::endl;
	std::cout << "|   |   |   |" << std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << "|   |   |   |" << std::endl;
	std::cout << "| " << gamefieldArray[2][0] << " | " << gamefieldArray[2][1] << " | " << gamefieldArray[2][2] << " |" << std::endl;
	std::cout << "|   |   |   |" << std::endl;
	std::cout << "-------------" << std::endl;
}

bool isWin(char gamefieldArray[][3])
{
	for (int i = 0; i < 3; ++i)
	{
		std::string row = "";
		std::string col = "";

		for (int j = 0; j < 3; ++j)
		{
			row += gamefieldArray[i][j];
			col += gamefieldArray[j][i];
		}

		if (row == "XXX" || col == "XXX" || row == "OOO" || col == "OOO") return true;
	}
	// Диагонали
	if (gamefieldArray[0][0] != ' ' && gamefieldArray[0][0] == gamefieldArray[1][1] && gamefieldArray[0][0] == gamefieldArray[2][2]) return true;
	else if (gamefieldArray[0][2] != ' ' && gamefieldArray[0][2] == gamefieldArray[1][1] && gamefieldArray[0][2] == gamefieldArray[2][0]) return true;


	return false;
}

void makeAMove(char gamefieldArray[][3], int playerNum, int turnCount, bool& endGame)
{
	char ch;
	if (playerNum == 1) ch = 'X';
	else ch = 'O';
	bool isCorrect = false;

	while (!isCorrect)
	{
		int x, y;
		std::cout << "\nPlayer " << playerNum << " turn: ";
		std::cin >> x >> y;
		if (x >= 0 && x < 3 && y >= 0 && y < 3 && gamefieldArray[x][y] == ' ')
		{
			isCorrect = true;
			gamefieldArray[x][y] = ch;
		}
		else std::cout << "Wrong turn! Please try again." << std::endl;
	}

	printGameField(gamefieldArray);

	if (isWin(gamefieldArray))
	{
		std::cout << "\nPlayer " << playerNum << " win!" << std::endl;
		endGame = true;
	}
	else if (turnCount == 9)
	{
		std::cout << "\nDraw" << std::endl;
		endGame = true;
	}
}

int main()
{
	char gamefield[3][3];

	// Инициализация игрового поля
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			gamefield[i][j] = ' ';
		}
	}

	int turnCount = 1;
	bool endGame = false;
	printGameField(gamefield);

	while (!endGame)
	{
		makeAMove(gamefield, (turnCount % 2 == 0 ? 2 : 1), turnCount, endGame);
		++turnCount;
	}

	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get();
}

/*
Задача 2. Крестики-нолики

	Старинная-добрая игра на страницах всех школьных тетрадей. Поле размером 3х3 представлено в виде двумерного массива с типом элементов char.
Помните тот символьный тип из предыдущего модуля? Теперь он нам и пригодится. Участвуют два игрока, которые ходят по очереди и ставят в указанные ими в
стандартном вводе координаты свой символ - ‘X’ или ‘O’ (буквы латинского алфавита). Как только у одного из игроков будет установлено подряд три крестика
или три нолика - он побеждает. Если свободных клеток не осталось, а трёх совпадающих элементов не найдено - объявляется ничья. Для простоты, мы не будем
рассматривать диагональные совпадения, а только строго вертикальные либо строго горизонтальные.

	Изначально всё поле инициализируется символом пробела - ‘ ‘. Это можно сделать сразу при объявлении, либо с помощью вложенного цикла. На каждом ходе,
при занятой клетке или при неверных координатах этой клетки должно быть выведено сообщение и игрок должен указать координаты клетки повторно. После каждого
хода надо выводить в консоль текущее состояние всего игрового поля, для наглядности.

	Сделаю ещё одну небольшую подсказку. Проверку на победу игрока, которую надо осуществлять после каждого хода, можно сделать с помощью вложенного цикла,
сразу проверяя и вертикаль и горизонталь а как именно - попробуйте догадаться сами.
*/


/*
		-------------
		|   |   |   |
		| X | O |   |
		|   |   |   |
		-------------
		|   |   |   |
		|   | O |   |
		|   |   |   |
		-------------
		|   |   |   |
		| X | X |   |
		|   |   |   |
		-------------
*/