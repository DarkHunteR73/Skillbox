#include "Tree.h"
#include <ctime>

int main()
{
	std::srand(std::time(nullptr));
	const int countOfTrees = 5;
	Tree* trees = new Tree[countOfTrees];

	Tree::getCountOfNeighbors(trees, countOfTrees);

	delete[] trees;
}

//	������� 1. ���������� ������� ������
//	
//	
//	��� ����� �������
//	
//	������ ����� ����������� ���� ������� � ����, ����� �� ��������.
//	����� ��������� ������ �� ������ ��������, � ����� ���������� ����� ���������� ������� ������������ �����.
//	
//	����� � ���� ���� ��������, �� ������ �� �������� 3�5 �������� ������� ������.
//	�� ������ �� ��� ����������� ��� �� 2 - 3 ������� �����.���� ������ ��������� ������ �� ������� � ������� ������.
//	
//	� ������ ��������� ������������ ��������� � ������ ���� �� ������ �����.
//	�������� ��� � ������� ����������������� �������� ���� ��������� ����� � ������� ����� 
//	����������� ����� ����� ����������� ����. ���� ���� ������� None � �������� �����, 
//	�� ��� ������������ � �� ���������� ������ �����.
//	
//	����� ����� ��������� ����� ������������ ����� �� �����.
//	��� �������� ����� �������� ����� ����������� ����. ��� ������� �����, ���� ������� ��� ������, 
//	��������� ������� ����� ���������� ������, ������� ������ � ��� �� ����� ������� �����.
//	
//	
//	������ � ������������
//	
//	���������� ��������� �������� � ������� ����, ��������� ��������� �����.
//	��� ����������� ��������� �������� ����������� ��������� this.
//	
//	
//	��� �����������
//	
//	������������ ������ ��������� � ������������ ����������� �������.