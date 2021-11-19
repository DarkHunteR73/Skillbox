#include "Branch.h"

Branch::Branch()
{
	countOfHouses = std::rand() % 2 + 2 + 1;
	nameOfResident = new std::string[countOfHouses];

	for (int i = 0; i < countOfHouses; ++i)
	{
		std::string tmpstr;

		while (true)
		{
			std::cout << "Enter the name of resident: ";
			std::getline(std::cin, tmpstr);

			if (tmpstr.empty())
				std::cerr << "Field cannot be empty! Try again." << std::endl;
			else break;
		}
		
		if (tmpstr != "none" && tmpstr != "None")
		{
			nameOfResident[i] = tmpstr;
		}
	}
}

Branch::~Branch() { delete[] nameOfResident; }

Branch* Branch::getBranchPtr(const std::string& request)
{
	for (int i = 0; i < countOfHouses; ++i)
	{
		if (nameOfResident[i] == request)
			return this;
	}

	return nullptr;
}

const std::string& Branch::getName(const int index) const { return nameOfResident[index]; }

int Branch::getCount() const { return countOfHouses; }
