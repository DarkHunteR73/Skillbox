#include "Company.h"

Company::Company()
{
	std::cout << "Enter the number of teams: ";
	int countOfTeams;
	std::cin >> countOfTeams;

	manager.resize(countOfTeams);
}

bool Company::checkEmployment()
{
	for (size_t i = 0; i < manager.size(); ++i)
	{
		std::vector<Task>& tmp = manager[i].getTeamRef();

		for (size_t j = 0; j < tmp.size(); ++j)
		{
			if (tmp[j] == Task::NONE)
			{
				return false;
			}
		}
	}

	std::cout << "\nAll employees are given tasks." << std::endl;
	return true;
}

void Company::distributeTasks()
{
	static int count = 0;
	std::cout << ++count << ". Enter the head command: ";
	int command;
	std::cin >> command;

	for (size_t i = 0; i < manager.size(); ++i)
	{
		manager[i].assignTasks(command);
	}
}
