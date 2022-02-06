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

//	Задача 1. Умный указатель на игрушку
//	
//	Что нужно сделать :
//	
//	Реализуйте умный указатель shared_ptr_toy с распределённым доступом и механикой подсчёта ссылок для класса Toy, 
//	реализованного в задании.
//	
//	Указатель должен иметь все стандартные методы класса и должен быть функциональной заменой использованию 
//	shared_ptr<Toy>.
//	
//	Также реализуйте свободную функцию make_shared_toy, принимающую набор аргументов и конструирующую игрушку 
//	либо от названия, либо копируя другую игрушку.
//	
//	
//	Чек - лист для проверки задачи
//	
//	Класс называется shared_ptr_toy
//	Реализован конструктор, конструктор копий, оператор присваивания копированием, 
//	деструктор и функция make_shared