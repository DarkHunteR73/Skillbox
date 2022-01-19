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

//	������� 2. ������ ��������� ��� - ��������
//	
//	
//	��� ����� �������
//	
//	��������� � ������� HTML - ��������.��� ����� ������� ������������ � ��������, 
//	�������������� �������� httpbin.org.������� ��� ������, ������� ����� ������ HTML - ��������.
//	����� �������� ������, ����� ������� ��������� ��������� �accept : text / html�.
//	� ���������� ������ ������� ��������� ������ � �������� ��� � �������.
//	
//	
//	������ � ������������
//	
//	��������� ������ ����������� ����� HTML - ������ <h1>< / h1>
//	
//	
//	��� �����������
//	
//	������������ ������ ��������� � ����������� ����������.