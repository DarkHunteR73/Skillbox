#pragma once

#include "Manager.h"

class Company
{
	std::vector<Manager> manager;

public:

	Company();
	bool checkEmployment();
	void distributeTasks();
};

