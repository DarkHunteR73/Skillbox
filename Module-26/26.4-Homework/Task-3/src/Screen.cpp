#include "Screen.h"

Screen::Screen() :screenVSize(50), screenHSize(80){}

void Screen::drawScreen()
{
	int vPointCoord = window.getVCoord(), hPointCoord = window.getHCoord(), windowVSize = window.getVSize(), windowHSize = window.getHSize();

	for (int v = 0; v < screenVSize; ++v)
	{		
		for (int h = 0; h < screenHSize; ++h)
		{
			if ((v >= vPointCoord && v < vPointCoord + windowVSize) && (h >= hPointCoord && h < hPointCoord + windowHSize))
			{
				std::cout << '1';
			}
			else
			{
				std::cout << '0';
			}
		}
		std::cout << std::endl;
	}
}

void Screen::move()
{
	std::cout << "Enter move vector: ";
	int tmpHCoord, tmpVCoord;
	std::cin >> tmpHCoord >> tmpVCoord;

	tmpHCoord += window.getHCoord();
	tmpVCoord += window.getVCoord();

	if (tmpHCoord >= 0 && tmpVCoord >= 0 && tmpHCoord + window.getHSize() < screenHSize && tmpVCoord + window.getVSize() < screenVSize)
	{
		window.setPoint(tmpHCoord, tmpVCoord);
		std::cout << "Window was moved to " << tmpHCoord << ';' << tmpVCoord << std::endl;
	}
	else
	{
		std::cerr << "Can't move window off the screen!" << std::endl;
	}
}

void Screen::resize()
{
	std::cout << "Enter new window size: ";
	int tmpHSize, tmpVSize;
	std::cin >> tmpHSize >> tmpVSize;

	if (tmpHSize > 0 && tmpVSize > 0 && window.getHCoord() + tmpHSize <= screenHSize && window.getVCoord() + tmpVSize <= screenVSize)
	{
		window.setSize(tmpHSize, tmpVSize);
		std::cout << "Window was resized to " << tmpHSize << '/' << tmpVSize << std::endl;
	}
	else if (tmpHSize < 0 || tmpVSize < 0)
	{
		std::cerr << "window dimensions cannot have negative values!" << std::endl;
	}
	else
	{
		std::cerr << "Window borders cannot go beyond the screen boundaries!" << std::endl;
	}
}
