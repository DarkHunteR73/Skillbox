#include <iostream>
#include <thread>
#include <chrono>

void initializeArray(bool arr[][12])
{
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			arr[i][j] = true;
		}
	}
}

bool areAnyBubblesLeft(bool arr[][12])
{
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			if (arr[i][j] == true) return true;
		}
	}
	return false;
}

void printArray(bool arr[][12])
{
	system("cls");	
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			if (arr[i][j] == true)
			{
				std::cout << 'O';
			}
			else std::cout << 'X';
		}
		std::cout << std::endl;
	}
}

int main()
{
	bool bubbleWrap[12][12];
	initializeArray(bubbleWrap);

	while (areAnyBubblesLeft(bubbleWrap))
	{
		printArray(bubbleWrap);

		bool correct = false;
		while (!correct)
		{
			std::cout << "\nPush the bubble: ";

			int x, y;
			std::cin >> x >> y;

			if (x >= 0 && x < 12 && y >= 0 && y < 12)
			{
				if (bubbleWrap[x][y] == true)
				{
					std::cout << "POP!" << std::endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
					bubbleWrap[x][y] = false;
					correct = true;
				}
				else std::cout << "This bubble is already burst." << std::endl;
			}
			else std::cout << "Wrong input! Please try again." << std::endl;
		}
	}
	std::cout << "You burst all the bubbles." << std::endl;
}

/*
Задача 7. Пупырка

После посылки из Китая осталась спец. плёнка для бережной перевозки груза — пупырка. Всего в пупырке 12 на 12 шариков-пузырьков. Состояние любого пузырька — 
это всегда либо он целый, либо нет, т.е. true или false (тип массива bool). Для начала, требуется реализовать отдельную функцию инициализации пупырки начальным
состоянием — полностью целая пупырка, т.е. все элементы true. Но это только самое начало.

Программа заключается в последовательном лопанье целых регионов пузырьков. Перед каждым таким лопаньем надо показывать пользователю полностью всю плёнку: 
o — это целый пузырёк, x — лопнутый. Это тоже надо выделить в отдельную функцию. Итак, как выглядит само лопанье. Пользователь вводит две координаты: 
координаты начала региона и конца прямоугольного региона. Сама процедура лопанья пузырей должна быть реализована с помощью отдельной функции, все аргументы
должны проверяться на их валидность, что они в в рамках диапазона возможных значений — иначе должна быть выведена ошибка. После лопанья каждого пузыря, который 
не был ещё лопнут до того, в консоль должно выводиться сообщение “Pop!”.

Лопанье должно продолжаться до последнего пузырька. Как только вся пупырка потрачена, программа заканчивает выполнение. В принципе, вы можете подсчитать
окончание в самой функции по отображению пузырьков плёнки, т.к. она выполняется после каждого лопанья.
*/