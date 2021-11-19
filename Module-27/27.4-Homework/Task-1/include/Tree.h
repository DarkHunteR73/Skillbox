#pragma once

#include "Branch.h"

class Tree
{
	int countOfBigBranches;
	Branch* branch;

public:

	Tree();
	~Tree();
	static void getCountOfNeighbors(const Tree* trees, const int arrSize);
};