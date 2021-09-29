#pragma once

#include "Window.h"

class Screen
{
	const int screenVSize;
	const int screenHSize;
	Window window;

public:

	Screen();
	void drawScreen();
	void move();
	void resize();
};