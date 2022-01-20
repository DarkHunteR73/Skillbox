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

//	������� 3. ������� � �����������
//	
//	
//	��� ����� �������
//	
//	�������� ������ � ������� httpbin.org, �������� ��� ���� ��������� �������������� ���������� � �������.
//	
//	��� �������� ���������� � �� �������� � ���������, � ����������� �� ������������.
//	������������ ��������������� ������ �� �������� ������ �� ����������, ���� �� ���������� �������� � 
//	��������� �post� ��� �get�, ��� ����� ��������, ��� ���� ���������� �������� � ��������� ��������� �� �� 
//	������ ��������� ��������.
//	
//	���� ������������ ������ �post�, �� ����������� POST - ������ � ��������� ������������ POST - ��������(��� �����).
//	���� �get�, �� GET - ������ � GET - �����������(����� � URL).
//	
//	�� ����������� ���������� �������, �������� ����� ������� � ����������� ������� � �������� �������� �� ���� 
//	form ��� args, � ����������� �� ���� ������� � ������� ������ ���� ����������� ��� �������� ���� ���������.
//	
//	
//	������ � ������������
//	
//	�������� HTTP - ���������, ��������� � GET - �������� ������������� ����� � URL ������� ����� 
//	��������������� �����. �������� ���������� ���������� �� �� �������� � ������� ������� � = �), 
//	� ���� ��������� ��������� ��������� �& �.
//	
//	������ ����������, �������� � URL ������� : ?foo=first&animal=cat&bar=third
//	
//	
//	��� �����������
//	
//	������������ ������ ��������� ��� ��������� ���������������� ������.