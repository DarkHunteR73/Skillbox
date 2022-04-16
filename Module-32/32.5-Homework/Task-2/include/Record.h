#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "nlohmann/json.hpp"

struct Record {
	std::string title;
	uint32_t releaseYear;
	std::vector<std::string> country;
	std::vector<std::string> productionCompany;
	std::vector<std::string> distributionCompany;
	std::vector<std::string> writtenBy;
	std::vector<std::string> director;
	std::vector<std::string> producer;
	std::vector<std::string> musicBy;
	uint32_t duration;
	uint32_t budget;
	int64_t boxOffice;
	std::map<std::string, std::string> cast;

	Record(const nlohmann::json& json);
};