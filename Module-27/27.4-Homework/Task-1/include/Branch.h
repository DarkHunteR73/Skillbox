#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

class Branch
{
	int countOfHouses;
	std::string* nameOfResident;

public:

	Branch();
	~Branch();
	Branch* getBranchPtr(const std::string& request);
	const std::string& getName(const int index) const;
	int getCount() const;
};