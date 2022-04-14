#include "MovieBase.h"

MovieBase::MovieBase(nlohmann::json& json) {
	for (auto it = json["Movie"].begin(); it != json["Movie"].end(); ++it) {
		base.insert(std::make_pair(it.key(), Record(*it)));
	}
}