#include "Order.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

std::queue<Order> incomingOrders;
std::vector<Order> ordersToDelivery;

std::mutex incomingOrdersMtx, ordersToDeliveryMtx, consoleMtx, kitchenMtx;

void ordersGenerator()
{
	while (true)
	{
		incomingOrdersMtx.lock();
		incomingOrders.push(Order());

		consoleMtx.lock();
		std::cout << "Incoming order #" << incomingOrders.back().getId() << ": "
				  << incomingOrders.back().getNameOfDish() << std::endl;
		consoleMtx.unlock();

		incomingOrdersMtx.unlock();

		std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 6 + 5));
	}
}

void orderExecution()
{
	while (true)
	{
		if (incomingOrders.empty())
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		else
		{
			incomingOrdersMtx.lock();
			Order currentOrder = incomingOrders.front();
			consoleMtx.lock();
			std::cout << "Order #" << currentOrder.getId() << ": "
					  << currentOrder.getNameOfDish()
					  << " is running" << std::endl;
			consoleMtx.unlock();
			incomingOrders.pop();
			incomingOrdersMtx.unlock();

			std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 11 + 5));

			ordersToDeliveryMtx.lock();

			consoleMtx.lock();
			std::cout << "Order #" << currentOrder.getId() << ": "
					  << currentOrder.getNameOfDish()
					  << " is ready" << std::endl;
			consoleMtx.unlock();

			ordersToDelivery.push_back(currentOrder);
			ordersToDeliveryMtx.unlock();
		}
	}
}

int main()
{
	std::srand(std::time(nullptr));

	int countOfDeliveries = 0;

	std::thread ordersThread(ordersGenerator);
	ordersThread.detach();

	std::thread kitchen(orderExecution);
	kitchen.detach();

	while (countOfDeliveries < 10)
	{
		std::this_thread::sleep_for(std::chrono::seconds(30));

		consoleMtx.lock();
		ordersToDeliveryMtx.lock();
		for (size_t i = 0; i < ordersToDelivery.size(); ++i)
		{
			std::cout << "Order #" << ordersToDelivery[i].getId()
					  << ": " << ordersToDelivery[i].getNameOfDish()
					  << " is sent to customer" << std::endl;
		}
		countOfDeliveries += ordersToDelivery.size();
		ordersToDelivery.clear();
		ordersToDeliveryMtx.unlock();
		consoleMtx.unlock();
	}
}

//	Задание 3. Симуляция работы кухни онлайн - ресторана
//	
//	
//	Что нужно сделать
//	
//	Требуется реализовать упрощённую модель работы кухни ресторана, работающего в режиме онлайн - доставки.
//	
//	Онлайн - заказ поступает каждые 5–10 секунд. Это случайное блюдо из пяти : пицца, суп, стейк, салат, суши.
//	Официант, принявший заказ онлайн, оставляет его у кухни.Если кухня свободна, 
//	она принимает заказ и спустя 5–15 секунд возвращает уже готовое блюдо на выдачу.
//	Время определяется случайным образом с помощью функции std::rand() в указанных диапазонах.
//	
//	Курьер приезжает каждые 30 секунд, забирает готовые блюда на выдаче и развозит их по заказчикам.
//	
//	Программа завершается после 10 успешных доставок.На каждом из этапов, будь то заказ, или готовка, 
//	или доставка заказа, выводятся соответствующие сообщения в консоль.
//	
//	
//	Советы и рекомендации
//	
//	Для симуляции готовки, используйте отдельный мьютекс и запускайте отдельную 
//	нить ожидания с вызовом detach для неё.
//	
//	
//	Что оценивается
//	
//	Корректность работы программы и безопасность использования общих ресурсов.