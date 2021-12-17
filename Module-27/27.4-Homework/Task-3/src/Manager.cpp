#include "Manager.h"

Manager::Manager()
{
	static int idCount = 0;
	this->id = ++idCount;

	std::cout << "Enter the number of employees in the team " << this->id << ": ";
	int countOfEmployees;
	std::cin >> countOfEmployees;

	team.assign(countOfEmployees, Task::NONE);
}

std::vector<Task>& Manager::getTeamRef() { return team; }

void Manager::assignTasks(int incomeCommand)
{
	std::srand(incomeCommand + id);
	int countOfTasks = std::rand() % team.size() + 1;

	for (size_t i = 0; countOfTasks && i < team.size(); ++i)
	{
		if (team[i] == Task::NONE)
		{
			team[i] = static_cast<Task>(std::rand() % 3 + 1);
			--countOfTasks;
		}
	}
}
