#include "Order.h"

Order::Order()
{
	static int count = 0;
	id = ++count;
	menuItem = static_cast<MenuItem>(std::rand() % 5);
}

int Order::getId() { return id; }

std::string Order::getNameOfDish()
{
	switch (menuItem)
	{
	case Order::MenuItem::PIZZA:
		return "Pizza";
	case Order::MenuItem::SOUP:
		return "Soup";
	case Order::MenuItem::STEAK:
		return "Steak";
	case Order::MenuItem::SALAD:
		return "Salad";
	case Order::MenuItem::SUSHI:
		return "Sushi";
	}
}
