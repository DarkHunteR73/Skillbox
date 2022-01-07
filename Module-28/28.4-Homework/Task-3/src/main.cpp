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

//	������� 3. ��������� ������ ����� ������ - ���������
//	
//	
//	��� ����� �������
//	
//	��������� ����������� ���������� ������ ������ ����� ���������, ����������� � ������ ������ - ��������.
//	
//	������ - ����� ��������� ������ 5�10 ������. ��� ��������� ����� �� ���� : �����, ���, �����, �����, ����.
//	��������, ��������� ����� ������, ��������� ��� � �����.���� ����� ��������, 
//	��� ��������� ����� � ������ 5�15 ������ ���������� ��� ������� ����� �� ������.
//	����� ������������ ��������� ������� � ������� ������� std::rand() � ��������� ����������.
//	
//	������ ��������� ������ 30 ������, �������� ������� ����� �� ������ � �������� �� �� ����������.
//	
//	��������� ����������� ����� 10 �������� ��������.�� ������ �� ������, ���� �� �����, ��� �������, 
//	��� �������� ������, ��������� ��������������� ��������� � �������.
//	
//	
//	������ � ������������
//	
//	��� ��������� �������, ����������� ��������� ������� � ���������� ��������� 
//	���� �������� � ������� detach ��� ��.
//	
//	
//	��� �����������
//	
//	������������ ������ ��������� � ������������ ������������� ����� ��������.