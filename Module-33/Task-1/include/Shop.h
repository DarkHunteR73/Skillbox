#pragma once

#include <iostream>
#include <exception>
#include <map>
#include <string>
#include <conio.h>

class Shop {
public:
	Shop();
	Shop(const Shop&)				 = delete;
	Shop(Shop&&) noexcept			 = delete;
	Shop& operator=(const Shop&)	 = delete;
	Shop& operator=(Shop&&) noexcept = delete;

	void add();
	void remove();
private:
	void insertNewItemToDatabase(std::string& item, int32_t quantity);
	void addItemToCart(std::string item, int32_t quantity);
	void removeItemFromCart(std::string item, int32_t quantity);

	std::map<std::string, int32_t> database;
	std::map<std::string, int32_t> shoppingCart;
};
