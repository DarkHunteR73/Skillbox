#include "Tree.h"

Tree::Tree()
{
	countOfBigBranches = std::rand() % 3 + 3;
	branch = new Branch[countOfBigBranches];
}

Tree::~Tree() { delete[] branch; }

void Tree::getCountOfNeighbors(const Tree* trees, const int arrSize)
{
	std::cout << "Enter a name to search: ";
	std::string nameToSearch;
	std::getline(std::cin, nameToSearch);

	Branch* branchPtr = nullptr;

	for (int i = 0; !branchPtr && i < arrSize; ++i)
	{
		for (int j = 0; !branchPtr && j < trees[i].countOfBigBranches; ++j)
		{
			branchPtr = trees[i].branch[j].getBranchPtr(nameToSearch);
		}
	}

	if (!branchPtr)
	{
		std::cout << "An elf with that name was not found." << std::endl;
		return;
	}

	int countOfNeighbors = 0;

	for (int i = 0; i < branchPtr->getCount(); ++i)
		if (!(branchPtr->getName(i).empty())) ++countOfNeighbors;

	std::cout << "Count of elves on this branch: " << countOfNeighbors << std::endl;
}
