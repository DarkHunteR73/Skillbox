#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <exception>

#include "Catch.h"

const size_t fieldSize{ 9 };
std::vector<Catch*> field(fieldSize, nullptr);

void castAFishingRod();

int main() {
	std::cout << "Gamefield size: " << fieldSize << std::endl;
	std::srand(std::time(nullptr));

	// Gamegield creation

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
	uint32_t attemptCounter{ 1 };

	while (!endGame) {
		try {
			castAFishingRod();
		} catch (const Fish&) {
			std::cout << "You caught fish! Congratulations!\nNumber of attempts: "
				<< attemptCounter << std::endl;
			endGame = true;
		} catch (const Boot&) {
			std::cout << "You caught boot! You lose." << std::endl;
			endGame = true;
		} catch (const std::runtime_error& e) {
			std::cerr << e.what() << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << ". Try again." << std::endl;
			++attemptCounter;
		}
	}
}

void castAFishingRod() {
	std::cout << "Enter the casting sector: ";
	int32_t input;
	std::cin >> input;

	if (input < 0 || input >= fieldSize)
		throw std::runtime_error{ "Out of bounds!" };

	if (field[input]) field[input]->get();
	else throw std::exception{ "Nothing" };
}

//	������� 2. ���� �� ����� ����
//	
//	��� ����� �������
//	
//	���������� ������� ���� - ��������� ����� ����. 
//	������� ���� ������������ ����� ������ �������� ��������� �����.
//	� ������ ���� � ����� �� ���� �������� � ������� ���������� ��������� ����� ����������� ����.
//	����� ��� ��, ��������� �������, �� �������� ����� �������������� � ��� ������.
//	����� � ���� ��� ���� �� ����� ���������� � ����� � ��� �� ������� ������������, 
//	��� � ��������� ����� ����� � ����� �� ��������.
//	
//	����� ���������� ������ � ��������� � ���� �� ��������, 
//	����� �������� �������� ����������� �������� ����� �������.
//	������ ������ � ������� ������, � ������� ��������� ���� �, ����� �������, ������� �.
//	���� ����� ����� �� ������ ������, �� ������ ���� ��������� ��������.���� ����� ������ �����, 
//	�� ���� ����������� � ������������� �����������.
//	
//	����������� ������ ����� � ������� ���������� : ����� �������� ������ ������ ���������� 
//  ����������� ���������������� ����������, ����� ���� ��������� ������ ����������� � ���������� 
//  ������������ �� �������� ������� � ���������� �������, ������� ��� ��� ����� �������������.
//  ���� �� ��� ������ �����, �� ������ ���������� ��������� � ��������� �����.
//	
//	
//	������������
//	
//	���������, ��� �� ������ ��������� � �������� ���������� ������������ ��� ������.
//	��� ����� ���� � �����, � ����.
//	
//	� ������� main ����������� ����������� ���� ��������� �������.
//	��� ����� �������� std::srand(std::time(nullptr)); 
//	� ����� ���� ������������ : field[std::rand() % 9].fish = new Fish(); 
//	��������� ���������% �� �� ������� �� ������� �������.
//	
//	
//	��� �����������
//	
//	������������ ������ ������� ������.�������� ������������� ����������.