#pragma once

#include <iostream>
#include <cmath>

class Shape abstract
{

	class Point
	{
	public:
		double x;
		double y;
	} center;

	enum class Color
	{
		NONE,
		RED,
		BLUE,
		GREEN
	} color;

protected:

	virtual double getArea() = 0;
	void outputColor();

public:

	Shape();
};


class Circle :
	public Shape
{
	double radius;
	virtual double getArea();

public:

	Circle();
	void getResult();
};


class Triangle :
	public Shape
{
	double side;

	virtual double getArea();

public:

	Triangle();
	void getResult();
};


class Square :
	public Shape
{
	double width;
	virtual double getArea();

protected:

	double getWidth();

public:

	Square();
	void getResult();
};


class Rectangle :
	public Square
{
	double height;
	virtual double getArea();

public:

	Rectangle();
	void getResult();
};