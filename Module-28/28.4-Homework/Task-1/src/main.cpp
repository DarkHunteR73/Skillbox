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

//	������� 1. ������ �� 100 ������
//	
//	
//	��� ����� �������
//	
//	���������� ��������� ���������� �� ������� �� 100 ������.
//	
//	����� ����� ������� � ����� �������. ����� ������� ����������� ������� �� ������������ �����.
//	������ �� ��� ����� � ������ ���������, ������� ����� ������� ������������� ��� ������, 
//	����� ����������� ���� � ������ � �������.
//	
//	������ ������� � ����������� ����� ������� ���������� � ���, ������� ������� ��� ��� ���� ������.
//	
//	��� ������ ��� ������ ��������� 100 - �������� �������, ������ ������������� � ��������� ������� � 
//	��������� ������������, ��������������� �� ����������� ��������� ������� �������.
//	
//	
//	������ � ������������
//	
//	����������� ���� ��� ���������� �������� ������� ������ � �����������.
//	
//	
//	��� �����������
//	
//	������������ ������ ���������, ������������ ���������������.