#include "Record.h"

Record::Record() {
	std::cout << "Movie title: ";
	std::getline(std::cin, title);

	std::cout << "Year of release: ";
	std::cin >> releaseYear;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Countries of production:" << std::endl;
	arrayFilling(country);

	std::cout << "Production companies:" << std::endl;
	arrayFilling(productionCompany);

	std::cout << "Distribution companies:" << std::endl;
	arrayFilling(distributionCompany);

	std::cout << "Written by:" << std::endl;
	arrayFilling(writtenBy);

	std::cout << "Directors:" << std::endl;
	arrayFilling(director);

	std::cout << "Producers:" << std::endl;
	arrayFilling(producer);

	std::cout << "Music by:" << std::endl;
	arrayFilling(musicBy);

	std::cout << "Duration: ";
	std::cin >> duration;

	std::cout << "Budget: ";
	std::cin >> budget;

	std::cout << "Box office: ";
	std::cin >> boxOffice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Cast:" << std::endl;

	while (true) {
		std::cout << "Add the actor: ";
		std::string actorName;
		std::getline(std::cin, actorName);

		if (actorName.empty()) break;
        if (!cast.contains(actorName)) {

            std::string characterName;
            while (characterName.empty()) {
                std::cout << "Enter character name for " << actorName << ": ";
                std::getline(std::cin, characterName);
            }

            cast.insert(std::make_pair(actorName, characterName));
        } else {
            std::cerr << actorName << " is already exist." << std::endl;
        }
    }
}

void Record::makeJson(nlohmann::json& json) {
	json["Title"] = title;
	json["Year of release"] = releaseYear;
	json["Country"] = country;
	json["Production company"] = productionCompany;
	json["Distribution company"] = distributionCompany;
	json["Written by"] = writtenBy;
	json["Director"] = director;
	json["Producer"] = producer;
	json["Music by"] = musicBy;
	json["Duration"] = duration;
	json["Budget"] = budget;
	json["Box office"] = boxOffice;
	json["Cast"] = cast;
}

void Record::arrayFilling(std::vector<std::string>& vec) {
	while (true) {
		std::cout << "[" << vec.size() + 1 << "]: ";
		std::string tmp;
		std::getline(std::cin, tmp);

		if (tmp.empty()) break;

		vec.push_back(tmp);
	}
}