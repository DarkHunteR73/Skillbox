﻿#include "nlohmann/json.hpp"
#include "MovieBase.h"
#include <iostream>
#include <fstream>

int main() {
	std::cout << "Enter path to database: ";
	std::string path;
	std::getline(std::cin, path);

	nlohmann::json json;
	std::ifstream file(path);
	if (file.is_open()) {
		file >> json;
		file.close();
	} else {
		std::cout << "Database is not found" << std::endl;
		return EXIT_FAILURE;
	}
	
	MovieBase movieBase(json);
	std::cout << "Loaded " << movieBase.size() << " records." << std::endl;

	std::cout << "Enter actor's name: ";
	std::string request;
	std::getline(std::cin, request);

	movieBase.search(request);
}

//	Задача 2. Анализ данных о фильмах
//	
//	
//	Что нужно сделать
//	
//	Используя модель данных из задачи №1, создайте JSON - документ, но теперь уже для пяти различных кинолент.
//	Ключи в этой JSON - базе данных должны быть названиями фильмов, а значениями служить уже словари с 
//	информацией о картинах.
//	
//	Загрузите базу данных в C++ - программу для последующего анализа.Предусмотрите следующий функционал : 
//	поиск актёра по имени(или фамилии) и вывод в консоль названий кинолент, в которых снимался актёр, и роль, 
//	которую он исполнял.
//	
//	
//	Что оценивается
//	
//	Валидность созданного JSON - документа с базой данных о фильмах.Корректность работы программы поиска актёра.
//	
//	
//	Как отправить работу на проверку
//	
//	Пришлите ссылку на repl.it или файл.срр с решением через форму ниже.