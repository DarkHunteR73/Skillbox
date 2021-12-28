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

//	������� 2. ��������� ������ �������
//	
//	
//	��� ����� �������
//	
//	� ������� ��������������� ���������� ������� ������ ���������������� �������.
//	
//	� ��� ����� ����������� � ������ ����� �������� ��� ������ ������ � ��������� ������������� A, B, C.
//	��� ��� ���� �� ���� � ��� �� ������ � ����� ����� �� ���� � ������ �����.
//	
//	�� ���� ������� ������� ������������� ����� ���������� ������ ���� �����.
//	��������� ������ ������ �����, ���� ��� ������� ����� �����������.
//	
//	� ������ ��������� ������������ ��������������� ������ ��� ������� ������ ����� � ���� �� �������(� ��������).
//	����� ����� ������ �������� ��� �������� �� �������� ���������� �������.
//	��� ������ ����� ������ �� ������, �� ������� �� ������������ ������� depart, 
//	������� ������������� � ��� ������� � �������.
//	
//	�� ���� ��������(�������� �� ������, �������� ���������� �����, ������� � �������) 
//	������ � �������� ������������ ������ ��������� ��������� � �������.
//	
//	��������� �����������, ����� �� ������� �������� ��� ��� ������.
//	
//	
//	������ � ������������
//	
//	����������� ��� ������� ��������� ������� � ����������� �������� � ������� ����.
//	
//	
//	��� �����������
//	
//	������������ ������ ��������� � ������������ ������������� ����� ��������.