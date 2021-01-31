#include "Window.h"

Window::Window() :windowVSize(6), windowHSize(20) {}

int Window::getVCoord()
{
	return point.vCoord;
}

int Window::getHCoord()
{
	return point.hCoord;
}

int Window::getVSize()
{
	return windowVSize;
}

int Window::getHSize()
{
	return windowHSize;
}

void Window::setPoint(int inHCoord, int inVCoord)
{
	point.hCoord = inHCoord;
	point.vCoord = inVCoord;
}

void Window::setSize(int inHSize, int inVSize)
{
	windowHSize = inHSize;
	windowVSize = inVSize;
}