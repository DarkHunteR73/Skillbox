#include "Request.h"
#include <string>

int main()
{
	Request request("http://httpbin.org");
	
	std::string cmd;

	while (cmd != "exit")
	{
		std::cout << "Enter command: ";
		std::cin >> cmd;

		if (cmd == "get")
			request.get();
		else if (cmd == "post")
			request.post();
		else if (cmd == "put")
			request.put();
		else if (cmd == "patch")
			request.patch();
		else if (cmd == "delete")
			request._delete();
	}
}

//	Задание 1. Пользовательские запросы
//	
//	
//	Что нужно сделать
//	
//	Реализуйте программу по осуществлению различных типов HTTP - запросов к сервису httpbin.org.
//	
//	Пользователь взаимодействует с программой с помощью команд : «get», «post», «put», «delete», «patch».
//	В зависимости от команды к серверу httpbin.org, осуществляется запрос того или иного типа.
//	Содержимое ответа сервера выводится в стандартный вывод.
//	
//	Программа завершается, когда пользователь вводит команду «ext».
//	
//	
//	Что оценивается
//	
//	Корректность выполнения запросов к сервису в зависимости от пользовательских команд.