#pragma once

#include "Record.h"

class MovieBase {
	std::map<std::string, Record> base;
public:
	MovieBase(const nlohmann::json& json);
	size_t size();
	void search(const std::string& request);
};