#include <iostream>

char player1Field[10][10], player1History[10][10], player2Field[10][10], player2History[10][10];

void pressEnter()
{
	std::cout << "\nPress 'Enter' to continue" << std::endl;
	std::cin.clear();
	//std::cin.ignore(32767, '\n');
	std::cin.get();
	system("cls");
}

void printField(char arr[][10], char arr2[][10])
{
	std::cout << "  ";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << ' ';
	}

	std::cout << "\t  ";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << '|';
		for (int j = 0; j < 10; ++j)
		{
			std::cout << arr[i][j] << '|';
		}

		std::cout << "\t" << i << '|';
		for (int j = 0; j < 10; ++j)
		{
			std::cout << arr2[i][j] << '|';
		}
		std::cout << std::endl;
	}
}

bool placeShip(char arr[][10], int size)
{
	int startPosX, startPosY, endPosX, endPosY;

	std::cout << "Enter start X Y: ";
	std::cin >> startPosX >> startPosY;

	if (size > 1)
	{
		std::cout << "Enter end X Y: ";
		std::cin >> endPosX >> endPosY;
	}
	else
	{
		endPosX = startPosX;
		endPosY = startPosY;
	}

	if (endPosX < startPosX) std::swap(startPosX, endPosX);
	if (endPosY < startPosY) std::swap(startPosY, endPosY);

	if (startPosX < 0 || endPosX >= 10 || startPosY < 0 || endPosY >= 10)
	{
		std::cerr << "Out of bounds!" << std::endl;
		return false;
	}

	int diffX = endPosX - startPosX;
	int diffY = endPosY - startPosY;

	if (diffX != 0)
	{
		if (diffX + 1 != size)
		{
			std::cerr << "Invalid ship size: " << size << std::endl;
			return false;
		}

		if (diffY != 0)
		{
			std::cerr << "Diagonal ships are not allowed!" << std::endl;
			return false;
		}

		int y = startPosY;
		for (int x = startPosX; x <= endPosX; ++x)
		{
			if (arr[x][y] != '_')
			{
				std::cerr << "Can't place ship here. Collision with another ship." << std::endl;
				return false;
			}
		}

		for (int x = startPosX; x <= endPosX; ++x)
		{
			arr[x][y] = '#';
		}
	}
	else
	{
		if (diffY + 1 != size)
		{
			std::cerr << "Invalid ship size: " << size << std::endl;
			return false;
		}

		if (diffX != 0)
		{
			std::cerr << "Diagonal ships are not allowed!" << std::endl;
			return false;
		}

		int x = startPosX;
		for (int y = startPosY; y <= endPosY; ++y)
		{
			if (arr[x][y] != '_')
			{
				std::cerr << "Can't place ship here. Collision with another ship." << std::endl;
				return false;
			}
		}

		for (int y = startPosY; y <= endPosY; ++y)
		{
			arr[x][y] = '#';
		}
	}
	return true;
}

void placeShips(char arr[][10], char arr2[][10])
{
	printField(arr, arr2);

	std::cout << "\nBIG ####:" << std::endl;

	while (!placeShip(arr, 4))
	{
		std::cout << "Please try again" << std::endl;
	}

	for (int i = 0; i < 2; ++i)
	{
		system("cls");
		printField(arr, arr2);

		std::cout << "\nMEDIUM ###:" << std::endl;

		while (!placeShip(arr, 3))
		{
			std::cout << "Please try again" << std::endl;
		}
	}


	for (int i = 0; i < 3; ++i)
	{
		system("cls");
		printField(arr, arr2);

		std::cout << "\nSMALL ##:" << std::endl;

		while (!placeShip(arr, 2))
		{
			std::cout << "Please try again" << std::endl;
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		system("cls");
		printField(arr, arr2);

		std::cout << "\nTINY #:" << std::endl;

		while (!placeShip(arr, 1))
		{
			std::cout << "Please try again" << std::endl;
		}
	}
}

bool attack(char enemyField[][10], char myField[][10], char myHistory[][10])
{
	printField(myField, myHistory);

	bool correct = false;
	int x, y;

	while (!correct)
	{
		std::cout << "\nEnter X Y: ";
		std::cin >> x >> y;


		if (x >= 0 && x < 10 && y >= 0 && y < 10)
		{
			correct = true;
		}
		else
		{
			std::cerr << "Invalid X Y! Try again" << std::endl;
		}
	}

	if (enemyField[x][y] == '#')
	{
		std::cout << "Damage!" << std::endl;
		enemyField[x][y] = 'X';
		myHistory[x][y] = 'X';
		return true;
	}
	else
	{
		std::cout << "Miss." << std::endl;
		enemyField[x][y] = '.';
		myHistory[x][y] = '.';
		return false;
	}
}

void initializeArray(char arr[][10])
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			arr[i][j] = '_';
		}
	}
}

int main()
{
	initializeArray(player1Field);
	initializeArray(player2Field);
	initializeArray(player1History);
	initializeArray(player2History);


	std::cout << "Player 1, place your ships!" << std::endl;
	pressEnter();
	placeShips(player1Field, player1History);
	std::cout << "\nShips are placed.";
	pressEnter();

	std::cout << "Player 2, place your ships!" << std::endl;
	pressEnter();
	placeShips(player2Field, player2History);
	std::cout << "\nShips are placed.";
	pressEnter();

	int player1HitsLeft = 20, player2HitsLeft = 20;
	while (true)
	{
		while (true)
		{
			std::cout << "Player 1, your turn." << std::endl;

			if (attack(player2Field, player1Field, player1History))
			{
				--player2HitsLeft;
				pressEnter();
			}
			else break;
		}
		if (player2HitsLeft==0)
		{
			std::cout << "Player 1 win! Congratulations!";
			return 0;
		}

		pressEnter();

		while (true)
		{
			std::cout << "Player 2, your turn." << std::endl;

			if (attack(player1Field, player2Field, player2History))
			{
				--player1HitsLeft;
				pressEnter();
			}
			else break;
		}
		if (player1HitsLeft == 0)
		{
			std::cout << "Player 2 win! Congratulations!";
			return 0;
		}

		pressEnter();
	}
}

//Морской бой
//
//    Требуется реализовать упрощённую игру в Морской бой.Игровое поле размером 10 на 10 клеток.Участвует двое игроков.В арсенале каждого из них :
//4 маленьких кораблика размером в одну клетку, 3 небольших корабля размером в две клетки, 2 средних корабля размером в три клетки и один большой корабль
//размером в четыре клетки.Для простоты, клетки поля пронумерованы по вертикали от 0 до 9, и по горизонтали также от 0 до 9. Мы не будем использовать классические
//наименования клеток, такие как B4, C6, а просто два индекса.Вначале игроки по очереди расставляют корабли, начиная с самых маленьких и заканчивая большими.
//Маленькие корабли в одну клетку расставляются с помощью указания лишь одной клетки - точки на поле, к примеру 2, 1. Корабли размерностью от двух клеток и выше,
//расставляются с помощью координат их начала и конца, к примеру : 0, 1 - 0, 3. Корабли могут быть установлены только строго вертикально, или горизонтально.
//Установка корабля по диагонали — недопустимо, в случае которого об этом тоже надо сообщить пользователю.Если корабль не может быть размещён на заданных клетках
//из - за того, что он столкнётся с другим кораблём(окажется на его клетках) или выйдет за пределы поля вообще, то игроку должно быть сделано предупреждение,
//после которого он должен переставить корабль на новые валидные координаты.Замечу, в нашем упрощённом варианте игры, мы не будем обсчитывать соприкосновения 
//кораблей друг с другом, а потому корабли вполне можно будет размещать друг к другу вплотную — борт к борту.После того как все корабли были расставлены 
//начинается игра.Игроки по очереди атакуют друг друга, называя координаты выстрела.После выстрела, в консоль выводится информация о его результате :
//попал или мимо.Если выстрел успешен, клетка, на которой был корабль(или его фрагмент) затирается и становится пустой.Игра заканчивается тогда,
//когда все корабли одной из сторон будут полностью уничтожены.Как только это произойдёт в консоль выводится информация с номером игрока, который победил.

/*
 |0|1|2|3|4|5|6|7|8|9|
0|@|_|.|_|_|@|_|X|_|_|
1|@|_|.|_|_|@|_|_|_|_|
2|@|_|_|_|_|_|_|_|_|_|
3|_|.|_|@|@|X|X|.|_|_|
4|_|_|_|_|_|_|_|_|_|_|
5|@|_|_|_|_|_|_|_|_|_|
6|_|_|.|_|_|_|_|@|@|@|
7|_|_|@|@|_|_|_|_|_|_|
8|@|_|_|_|_|@|_|_|_|@|
9|_|_|_|_|_|_|_|_|_|@|
*/