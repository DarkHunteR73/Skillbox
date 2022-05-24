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