#include <iostream>
#include <vector>
#include <cpr/cpr.h>

int main()
{
	cpr::Url url("http://httpbin.org");
	std::vector<cpr::Pair> args;
	cpr::Response response;

	while (true)
	{
		std::string tmpkey, tmpvalue;
		std::cout << "Enter an argument: ";
		std::cin >> tmpkey;

		if (tmpkey != "get" && tmpkey != "post")
		{
			std::cout << "Enter a value: ";
			std::cin >> tmpvalue;

			args.push_back({ tmpkey,tmpvalue });
		}
		else
		{
			std::string adressTail;

			if (tmpkey == "get")
			{
				adressTail = "/get";

				if (!args.empty())
				{
					adressTail += '?';

					for (size_t i = 0; i < args.size(); ++i)
					{
						adressTail += args[i].key + '=' + args[i].value;

						if (i < args.size() - 1)
							adressTail += '&';
					}
				}

				response = cpr::Get(url + adressTail);
				break;
			}
			else
			{
				adressTail = "/post";

				response = cpr::Post(url + adressTail, cpr::Payload(args.begin(), args.end()));
				break;
			}
		}
	}

	std::cout << response.text << std::endl;
}

//	Задание 3. Запросы с аргументами
//	
//	
//	Что нужно сделать
//	
//	Сделайте запрос к сервису httpbin.org, отправив при этом несколько дополнительных аргументов с данными.
//	
//	Все названия аргументов и их значения — строковые, и принимаются от пользователя.
//	Пользователь последовательно вводит их названия вместе со значениями, пока не встретится аргумент с 
//	названием «post» или «get», что будет означать, что ввод аргументов закончен и требуется отправить их на 
//	сервер выбранным способом.
//	
//	Если пользователь выбрал «post», то выполняется POST - запрос и аргументы отправляются POST - способом(как форма).
//	Если «get», то GET - запрос с GET - аргументами(прямо в URL).
//	
//	По результатам выполнения запроса, выведите ответ сервера в стандартную консоль и обратите внимание на поля 
//	form или args, в зависимости от типа запроса в которых должны быть перечислены все введённые вами аргументы.
//	
//	
//	Советы и рекомендации
//	
//	Согласно HTTP - стандарту, аргументы в GET - запросах перечисляются прямо в URL запроса после 
//	вопросительного знака. Названия аргументов отделяются от их значений с помощью символа « = »), 
//	а сами аргументы разделены символами «& ».
//	
//	Пример аргументов, заданных в URL запроса : ?foo=first&animal=cat&bar=third
//	
//	
//	Что оценивается
//	
//	Корректность работы программы при различных пользовательских данных.