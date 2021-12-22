#include "Swimmer.h"
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>

std::vector<Swimmer> swimmer(6);
std::vector<std::thread> threadVec(6);
std::vector<Swimmer*> result;
std::mutex consoleMtx, resultMtx;

void swim(Swimmer& swimmer)
{
	double distance = 0;

	while (distance < 100)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		distance += swimmer.getSpeed();
		if (distance > 100)
			distance = 100;

		consoleMtx.lock();
		std::cout << swimmer.getName() << '\t' << distance << std::endl;
		consoleMtx.unlock();
	}

	resultMtx.lock();
	result.push_back(&swimmer);
	resultMtx.unlock();
}

int main()
{
	std::cout << "\nSwim started!" << std::endl;

	for (size_t i = 0; i < threadVec.size(); ++i)
		threadVec[i] = std::thread(swim, std::ref(swimmer[i]));

	for (size_t j = 0; j < threadVec.size(); ++j)
		threadVec[j].join();

	std::cout << "Swim finished!" << std::endl;
	std::cout << "\nResults:" << std::endl;

	for (size_t k = 0; k < result.size(); ++k)
		std::cout << k + 1 << ". " << result[k]->getName() << std::endl;
}

//	Задание 1. Заплыв на 100 метров
//	
//	
//	Что нужно сделать
//	
//	Реализуйте симуляцию состязаний по заплыву на 100 метров.
//	
//	Всего шесть дорожек и шесть пловцов. Имена пловцов указываются вначале из стандартного ввода.
//	Каждый из них плывёт с разной скоростью, которая также задаётся пользователем при старте, 
//	через стандартный ввод в метрах в секунду.
//	
//	Каждую секунду в стандартный вывод выдаётся информация о том, сколько проплыл тот или иной пловец.
//	
//	Как только все пловцы коснулись 100 - метровой отметки, заплыв заканчивается и выводится таблица с 
//	итоговыми результатами, отсортированная по возрастанию итогового времени заплыва.
//	
//	
//	Советы и рекомендации
//	
//	Используйте нити для реализации движения каждого пловца в отдельности.
//	
//	
//	Что оценивается
//	
//	Корректность работы программы, использующей многопоточность.