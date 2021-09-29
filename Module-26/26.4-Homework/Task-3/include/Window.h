#pragma once

#include <iostream>

class Window
{
	struct Point
	{
		int hCoord = 5;
		int vCoord = 5;
	} point;

	int windowVSize;
	int windowHSize;

public:

	Window();
	int getVCoord();
	int getHCoord();
	int getVSize();
	int getHSize();
	void setPoint(int inHCoord, int inVCoord);
	void setSize(int inHSize, int inVSize);
};