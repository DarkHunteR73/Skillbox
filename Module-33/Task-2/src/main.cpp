#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Catch.h"

const size_t fieldSize{ 9 };

int main() {
	std::cout << "Gamefield size: " << fieldSize << std::endl;
	std::srand(std::time(nullptr));

	// Gamegield creation
	std::vector<Catch*> field(fieldSize, nullptr);

	field[std::rand() % fieldSize] = new Fish;

	size_t bootCount{ 0 };
	while (bootCount < 3) {
		size_t sector{ std::rand() % fieldSize };

		if (!field[sector]) {
			field[sector] = new Boot;
			++bootCount;
		}
	}

	// Game process
	bool endGame{ false };
	size_t attemptCounter{ 1 };

	while (!endGame) {
		std::cout << "Enter the casting sector: ";
		int32_t input;
		std::cin >> input;

		if (field[input]) {
			try {
				field[input]->get();
			} catch (const Fish&) {
				std::cout << "You caught fish! Congratulations!\nNumber of attempts: "
					<< attemptCounter << std::endl;
				endGame = true;
			} catch (const Boot&) {
				std::cout << "You caught boot! You lose." << std::endl;
				endGame = true;
			}
		} else {
			std::cout << "Nothing. Try again." << std::endl;
			++attemptCounter;
		}
	}
}

//	Задание 2. Игра по ловле рыбы
//	
//	Что нужно сделать
//	
//	Реализуйте простую игру - симуляцию ловли рыбы. 
//	Игровое поле представляет собой девять секторов условного пруда.
//	В начале игры в одном из этих секторов с помощью генератора случайных чисел оказывается рыба.
//	Точно так же, случайным образом, по секторам пруда распределяются и три сапога.
//	Сапог и рыба при этом не могут находиться в одном и том же секторе одновременно, 
//	как и несколько сапог сразу в одном из секторов.
//	
//	Игрок закидывает удочку с приманкой в один из секторов, 
//	номер которого вводится стандартным способом через консоль.
//	Задача игрока — угадать сектор, в котором находится рыба и, таким образом, поймать её.
//	Если игрок попал на пустой сектор, то удочку надо забросить повторно.Если игрок поймал сапог, 
//	то игра завершается с отрицательным результатом.
//	
//	Реализовать задачу нужно с помощью исключений : когда успешный заброс удочки генерирует 
//  специальное пользовательское исключение, после чего программа должна завершиться и оповестить 
//  пользователя об успешной рыбалке и количестве попыток, которое ему для этого потребовалось.
//  Если же был пойман сапог, то должно выводиться сообщение о неудачной ловле.
//	
//	
//	Рекомендации
//	
//	Вспомните, что вы можете выбросить в качестве исключения произвольный тип данных.
//	Это может быть и сапог, и рыба.
//	
//	В функции main потребуется расположить рыбу случайным образом.
//	Для этого сделайте std::srand(std::time(nullptr)); 
//	а затем само расположение : field[std::rand() % 9].fish = new Fish(); 
//	Благодаря оператору% вы не выйдете за пределы массива.
//	
//	
//	Что оценивается
//	
//	Корректность работы игровой логики.Точность использования исключений.