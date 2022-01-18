#include "Request.h"

void Request::get()
{
	response = cpr::Get(url + "/get");
	std::cout << response.text << std::endl;
}

void Request::post()
{
	response = cpr::Post(url + "/post");
	std::cout << response.text << std::endl;
}

void Request::put()
{
	response = cpr::Put(url + "/put");
	std::cout << response.text << std::endl;
}

void Request::patch()
{
	response = cpr::Patch(url + "/patch");
	std::cout << response.text << std::endl;
}

void Request::_delete()
{
	response = cpr::Delete(url + "/delete");
	std::cout << response.text << std::endl;
}
