#include "Record.h"

Record::Record(const nlohmann::json& json)
	:title(json["Title"]),
	releaseYear(json["Year of release"]),
	country(json["Country"].get<std::vector<std::string>>()),
	productionCompany(json["Production company"].get<std::vector<std::string>>()),
	distributionCompany(json["Distribution company"].get<std::vector<std::string>>()),
	writtenBy(json["Written by"].get<std::vector<std::string>>()),
	director(json["Director"].get<std::vector<std::string>>()),
	producer(json["Producer"].get<std::vector<std::string>>()),
	musicBy(json["Music by"].get<std::vector<std::string>>()),
	duration(json["Duration"]),
	budget(json["Budget"]),
	boxOffice(json["Box office"]),
	cast(json["Cast"].get<std::map<std::string, std::string>>()) {}
