#pragma once

#include "Record.h"

class MovieBase {
	std::map<std::string, Record> base;
public:
	MovieBase(nlohmann::json& json);
};