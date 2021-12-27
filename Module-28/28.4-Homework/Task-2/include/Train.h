#pragma once

#include <iostream>

class Train
{
	char symbol;
	uint32_t timeToArrival;

	uint32_t setTime();

public:

	Train();
	uint32_t getTime();
	char getSymbol();
};

