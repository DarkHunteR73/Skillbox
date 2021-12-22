#pragma once

#include <string>
#include <iostream>

class Swimmer
{
	std::string name;
	double speed;

public:

	Swimmer();
	Swimmer(std::string inName, double inSpeed);
	std::string getName();
	double getSpeed();
};

