#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main()
{
	cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
					  cpr::Header({ {"Accept", "text/html"} }));

	if (r.status_code == 200)
	{
		int headerEndPos = r.text.find("</h1>");
		for (int i = r.text.find("<h1>") + 4; i < headerEndPos; ++i)
			std::cout << r.text[i];
	}
	else
	{
		std::cout << "Something went wrong!";
	}
	std::cout << std::endl;
}

//	Задание 2. Захват заголовка веб - страницы
//	
//	
//	Что нужно сделать
//	
//	Запросите с сервера HTML - страницу.Для этого изучите документацию о запросах, 
//	поддерживаемых сервисом httpbin.org.Найдите там запрос, который выдаёт именно HTML - страницу.
//	Затем сделайте запрос, явным образом используя заголовок “accept : text / html”.
//	В полученном ответе найдите заголовок статьи и выведите его в консоль.
//	
//	
//	Советы и рекомендации
//	
//	Заголовок статьи размещается между HTML - тегами <h1>< / h1>
//	
//	
//	Что оценивается
//	
//	Корректность работы программы и полученного результата.