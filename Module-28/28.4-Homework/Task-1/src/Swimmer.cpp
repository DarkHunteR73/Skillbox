#include "Swimmer.h"

Swimmer::Swimmer()
{
	static int count = 0;
	std::cout << "Swimmer " << ++count << ':' << std::endl;
	std::cout << "Eneter the name: ";
	std::getline(std::cin, name);
	std::cout << "Enter speed: ";
	std::cin >> speed;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Swimmer::Swimmer(std::string inName, double inSpeed)
	:name(inName),speed(inSpeed) {}

std::string Swimmer::getName() { return name; }

double Swimmer::getSpeed() { return speed; }
