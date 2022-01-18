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

//	������� 1. ���������������� �������
//	
//	
//	��� ����� �������
//	
//	���������� ��������� �� ������������� ��������� ����� HTTP - �������� � ������� httpbin.org.
//	
//	������������ ��������������� � ���������� � ������� ������ : �get�, �post�, �put�, �delete�, �patch�.
//	� ����������� �� ������� � ������� httpbin.org, �������������� ������ ���� ��� ����� ����.
//	���������� ������ ������� ��������� � ����������� �����.
//	
//	��������� �����������, ����� ������������ ������ ������� �ext�.
//	
//	
//	��� �����������
//	
//	������������ ���������� �������� � ������� � ����������� �� ���������������� ������.