#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>

enum class Task { NONE, A, B, C };

class Manager
{
	int id;
	std::vector<Task> team;

public:

	Manager();
	std::vector<Task>& getTeamRef();
	void assignTasks(int incomeCommand);
};

