#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");	
	
	for (int buckwheat = 100, month = 1; buckwheat > 0; month++)
	{
		buckwheat -= 4;
		std::cout << "К концу " << month << " месяца останется: " << buckwheat << " кг\n";		
	}
	return 0;
}
