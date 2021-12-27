#include "Train.h"

Train::Train()
{
	static char symbolCount = 'A';
	symbol = symbolCount++;

	timeToArrival = setTime();
}

uint32_t Train::getTime()
{
	return timeToArrival;
}

char Train::getSymbol()
{
	return symbol;
}

uint32_t Train::setTime()
{
	uint32_t tmpTime;
	std::cout << "Train " << symbol << ". Enter time to arrival: ";
	std::cin >> tmpTime;

	return tmpTime;
}

