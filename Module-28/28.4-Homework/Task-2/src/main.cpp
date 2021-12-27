#include "Train.h"
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

const int SIZE = 3;

std::vector<std::pair<Train, std::thread>> train(SIZE);
std::mutex consoleMtx, stationMtx;

void moveToStation(Train& train)
{
	std::this_thread::sleep_for(std::chrono::seconds(train.getTime()));

	consoleMtx.lock();
	std::cout << "Train " << train.getSymbol() << " is waiting." << std::endl;
	consoleMtx.unlock();

	while (!stationMtx.try_lock())
		std::this_thread::sleep_for(std::chrono::seconds(1));

	consoleMtx.lock();
	std::cout << "Train " << train.getSymbol() << " has arrived to station." << std::endl;
	consoleMtx.unlock();

	while (true)
	{
		std::string cmd;
		std::cin >> cmd;

		if (cmd == "depart")
		{
			stationMtx.unlock();

			consoleMtx.lock();
			std::cout << "Train " << train.getSymbol() << " was sent from the station." << std::endl;
			consoleMtx.unlock();

			break;
		}
	}
}

int main()
{
	for (size_t i = 0; i < train.size(); ++i)
	{
		train[i].second = std::thread(moveToStation, std::ref(train[i].first));
	}

	for (size_t j = 0; j < train.size(); ++j)
	{
		train[j].second.join();
	}

	std::cout << "\nAll trains has arrived to the station." << std::endl;
}

//	Задание 2. Симуляция работы вокзала
//	
//	
//	Что нужно сделать
//	
//	С помощью многопоточности реализуйте простую модель железнодорожного вокзала.
//	
//	С трёх точек отправления в разное время отбывают три разных поезда с условными обозначениями A, B, C.
//	Все они идут на один и тот же вокзал и могут дойти до него в разное время.
//	
//	На этом целевом вокзале единовременно может находиться только один поезд.
//	Остальные поезда должны ждать, пока уже занятое место освободится.
//	
//	В начале программы пользователь последовательно вводит для каждого поезда время в пути до вокзала(в секундах).
//	После этого поезда начинают своё движение за заданное количество времени.
//	Как только поезд прибыл на вокзал, он ожидает от пользователя команды depart, 
//	которая сигнализирует о его отбытии с вокзала.
//	
//	По всем событиям(прибытие на вокзал, ожидание свободного места, отбытие с вокзала) 
//	вместе с условным обозначением поезда выводятся сообщения в консоль.
//	
//	Программа завершается, когда на вокзале побывают все три поезда.
//	
//	
//	Советы и рекомендации
//	
//	Используйте для вокзала отдельный мьютекс и симулируйте ожидание с помощью него.
//	
//	
//	Что оценивается
//	
//	Корректность работы программы и безопасность использования общих ресурсов.