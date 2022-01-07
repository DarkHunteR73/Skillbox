#pragma once

#include <cstdlib>
#include <string>

class Order
{
	int id;
	enum class MenuItem
	{
		PIZZA,
		SOUP,
		STEAK,
		SALAD,
		SUSHI
	} menuItem;

public:

	Order();
	int getId();
	std::string getNameOfDish();
};

