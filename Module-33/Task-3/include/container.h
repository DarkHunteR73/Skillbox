#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <initializer_list>

template <typename T, typename Val>
class Container {
public:
	Container() {}

	Container(std::initializer_list<std::pair<T, Val>> list) 
			 :storage{ list } {}

	void add(T key, Val value) {
		storage.push_back(std::make_pair(key, value));
	}

	void remove(T key) {
		for (auto it = storage.begin(); it != storage.end();) {
			if (it->first == key) {
				it = storage.erase(it);
			} else {
				++it;
			}
		}
	}

	void print() {
		if (storage.empty()) {
			std::cout << "Countainer is empty." << std::endl;
			return;
		}

		for (auto it = storage.begin(); it != storage.end(); ++it) {
			std::cout << it->first << " : " << it->second << std::endl;
		}
	}

	void find(T key) {
		size_t count{ 0 };

		for (auto it = storage.begin(); it != storage.end(); ++it) {
			if (it->first == key) {
				std::cout << it->first << " : " << it->second << std::endl;
				++count;
			}
		}

		if (!count) {
			std::cout << "Nothing found." << std::endl;
		}
	}

private:
	std::vector<std::pair<T, Val>> storage;
};