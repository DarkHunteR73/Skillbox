#include <iostream>
#include <cmath>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");

	float x, y;
	while (true)
	{
		cout << "Введите  местоположение коня: ";
		cin >> x >> y;
		if (x >= 0 && y >= 0 && x < 0.8 && y < 0.8) break;
		cout << "Ошибка! Введите снова.\n";
	}

	x = floor(x * 10);
	y = floor(y * 10);

	float turnX, turnY;
	while (true)
	{
		cout << "Введите координаты точки: ";
		cin >> turnX >> turnY;
		if (turnX >= 0 && turnY >= 0 && turnX < 0.8 && turnY < 0.8) break;
		cout << "Ошибка! Введите снова.\n";
	}

	turnX = floor(turnX * 10);
	turnY = floor(turnY * 10);

	cout << "Конь в клетке (" << x << ", " << y << "). Точка в клетке (" << turnX << ", " << turnY << ")\n";

	turnX -= x;
	turnY -= y;

	float distance = sqrt(turnX * turnX + turnY * turnY);
	if (abs(distance) > 2.236 && abs(distance < 2.237)) cout << "Да, конь может ходить в эту точку.\n";
	else cout << "Нет, конь не может ходить в эту точку.\n";
	return 0;
}