#include "Shop.h"

Shop::Shop()
	:shoppingCart{} {
	std::cout << "Database initialization..." << std::endl;
	std::string itemName{};
	int32_t quantity{};
	char input{};

	do {
		while (true) {
			std::cout << "Enter item name and quantity: ";
			std::cin >> itemName >> quantity;

			try {
				insertNewItemToDatabase(itemName, quantity);
				break;
			} catch (const std::invalid_argument& e) {
				std::cerr << e.what() << std::endl;
			}
		}

		std::cout << "Do you want to add one more item? (y/n)" << std::endl;
		input = _getch();
	} while (input == 'y');

	std::cout << "Database initialization finished..." << std::endl;
}

void Shop::add() {
	std::cout << "Enter product name and quantity: ";
	std::string item{};
	int32_t quantity{};

	std::cin >> item >> quantity;

	try {
		addItemToCart(item, quantity);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void Shop::remove() {
	std::cout << "Enter product name and quantity: ";
	std::string item{};
	int32_t quantity{};

	std::cin >> item >> quantity;

	try {
		removeItemFromCart(item, quantity);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void Shop::insertNewItemToDatabase(std::string& itemName, int32_t quantity) {
	if (database.contains(itemName)) {
		std::string message = '"' + itemName + '"' + " is already exists.";
		throw std::invalid_argument{ message };
	}

	if (quantity < 0) {
		throw std::invalid_argument{ "Quantity can't be less than zero." };
	}

	database.insert(std::make_pair(itemName, quantity));
}

void Shop::addItemToCart(std::string item, int32_t quantity) {
	if (database.empty()) {
		throw std::runtime_error{ "Database is empty." };
	}

	if (!database.contains(item)) {
		std::string message = '"' + item + '"' + " is not in the database.";
		throw std::invalid_argument{ message };
	}

	if (database[item] < quantity) {
		throw std::invalid_argument{ "This amount of goods is not in the database." };
	}

	shoppingCart.insert(std::make_pair(item, quantity));
	database[item] -= quantity;
}

void Shop::removeItemFromCart(std::string item, int32_t quantity) {
	if (shoppingCart.empty()) {
		throw std::runtime_error{ "Cart is empty." };
	}

	if (!shoppingCart.contains(item)) {
		std::string message = '"' + item + '"' + " is not in the cart.";
		throw std::invalid_argument{ message };
	}

	if (shoppingCart[item] < quantity) {
		throw std::invalid_argument{ "This amount of goods is not in the cart." };
	} else if (shoppingCart[item] > quantity) {
		shoppingCart[item] -= quantity;
	} else {
		shoppingCart.erase(item);
	}

	database[item] += quantity;
}
