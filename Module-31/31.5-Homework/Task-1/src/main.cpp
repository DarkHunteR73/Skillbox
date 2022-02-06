#include "my_memory.h"
#include <iostream>
#include <string>

struct MyStruct {
	std::string str;
	int count;

	MyStruct(std::string _str, int _count) :str(_str), count(_count) {}
};

int main() {
	my::shared_ptr<MyStruct> p;
	auto ptr = my::make_shared<MyStruct>("asdasd", 100);
	p = ptr;
	std::cout << ptr->str << ' ' << ptr->count << std::endl;
	my::shared_ptr<std::string> p_str;
	p_str = new std::string("fgdfgdfsdfsdfs");
	my::shared_ptr<std::string> ap_str = p_str;
	ap_str = p_str;
	std::cout << *ap_str << std::endl;
}

//	������ 1. ����� ��������� �� �������
//	
//	��� ����� ������� :
//	
//	���������� ����� ��������� shared_ptr_toy � ������������� �������� � ��������� �������� ������ ��� ������ Toy, 
//	�������������� � �������.
//	
//	��������� ������ ����� ��� ����������� ������ ������ � ������ ���� �������������� ������� ������������� 
//	shared_ptr<Toy>.
//	
//	����� ���������� ��������� ������� make_shared_toy, ����������� ����� ���������� � �������������� ������� 
//	���� �� ��������, ���� ������� ������ �������.
//	
//	
//	��� - ���� ��� �������� ������
//	
//	����� ���������� shared_ptr_toy
//	���������� �����������, ����������� �����, �������� ������������ ������������, 
//	���������� � ������� make_shared