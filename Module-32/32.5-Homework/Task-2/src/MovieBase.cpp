#include "MovieBase.h"

MovieBase::MovieBase(const nlohmann::json& json) {
	for (auto it = json["Movie"].begin(); it != json["Movie"].end(); ++it) {
		base.insert(std::make_pair(it.key(), Record(*it)));
	}
}

size_t MovieBase::size() { return base.size(); }

void MovieBase::search(const std::string& request) {
	std::vector<std::pair<std::string, std::string>> result;
	for (auto it = base.begin(); it != base.end(); ++it) {
		if (it->second.cast.contains(request)) {
			result.push_back(std::make_pair(it->second.title, it->second.cast[request]));
		}
	}

	std::cout << "Results for request \"" << request << "\": " << std::endl;

	if (!result.empty()) {
		for (auto i : result) {
			std::cout << "\t\"" << i.first << '\"' << ": " << i.second << std::endl;
		}
	} else {
		std::cout << "Nothing found." << std::endl;
	}
}