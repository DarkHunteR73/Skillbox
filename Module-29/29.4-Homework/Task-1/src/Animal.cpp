#include "Animal.h"

std::string Dog::voice(Cat& other) { return "Meow Bark"; }
std::string Dog::voice(Dog& other) { return "Woof Woof"; }
std::string Dog::voice(Animal& a) { return a.voice(*this); }

std::string Cat::voice(Cat& other) { return "Purr Purr"; }
std::string Cat::voice(Dog& other) { return "Bark Meow"; }
std::string Cat::voice(Animal& a) { return a.voice(*this); }
