#pragma once

#include <string>

class Animal
{
public:
	virtual std::string voice(class Cat&) = 0;
	virtual std::string voice(class Dog&) = 0;
	virtual std::string voice(Animal&) = 0;
};

class Dog :virtual public Animal
{
	virtual std::string voice(Cat& other);
	virtual std::string voice(Dog& other);
public:
	virtual std::string voice(Animal& a);
};

class Cat :virtual public Animal
{
	virtual std::string voice(Cat& other);
	virtual std::string voice(Dog& other);
public:
	virtual std::string voice(Animal& a);
};