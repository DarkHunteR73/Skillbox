#include "Shape.h"

Shape::Shape()
{
	std::cout << "Enter the center coordintes: ";
	std::cin >> center.x >> center.y;

	std::cout << "Enter the color: ";
	std::string clr;
	std::cin >> clr;

	if (clr == "red")
		color = Color::RED;
	else if (clr == "blue")
		color = Color::BLUE;
	else if (clr == "green")
		color = Color::GREEN;
	else color = Color::NONE;
}

void Shape::outputColor()
{
	std::cout << "Color: ";

	switch (color)
	{
	case Shape::Color::RED:
		std::cout << "Red";
		break;
	case Shape::Color::BLUE:
		std::cout << "Blue";
		break;
	case Shape::Color::GREEN:
		std::cout << "Green";
		break;
	default:
		std::cout << "None";
		break;
	}

	std::cout << std::endl;
}

Circle::Circle()
{
	std::cout << "Enter the radius: ";
	std::cin >> radius;
}

void Circle::getResult()
{
	system("cls");
	std::cout << "Type: Circle" << std::endl;
	Shape::outputColor();
	std::cout << "Area: " << getArea() << std::endl;
	int frameSide = static_cast<int>(std::ceil(radius * 2));
	std::cout << "Frame: " << frameSide << 'x' << frameSide << std::endl;
}

double Circle::getArea() { return 3.141592 * radius * radius; }

Triangle::Triangle()
{
	std::cout << "Enter the side length: ";
	std::cin >> side;
}

void Triangle::getResult()
{
	system("cls");

	std::cout << "Type: Triangle" << std::endl;
	Shape::outputColor();
	std::cout << "Area: " << getArea() << std::endl;

	int frameWidth = static_cast<int>(std::ceil(side));
	int frameHeight = static_cast<int>(std::ceil(side * std::sqrt(3) / 2));

	std::cout << "Frame: " << frameWidth << 'x' << frameHeight << std::endl;
}

double Triangle::getArea() { return side * side * std::sqrt(3) / 4; }

Square::Square()
{
	std::cout << "Enter the width: ";
	std::cin >> width;
}

void Square::getResult()
{
	system("cls");

	std::cout << "Type: Square" << std::endl;
	Shape::outputColor();
	std::cout << "Area: " << getArea() << std::endl;

	int frameWidth = static_cast<int>(std::ceil(width));

	std::cout << "Frame: " << frameWidth << 'x' << frameWidth << std::endl;
}

double Square::getArea() { return width * width; }

double Square::getWidth() { return width; }

Rectangle::Rectangle()
{
	std::cout << "Enter the height: ";
	std::cin >> height;
}

void Rectangle::getResult()
{
	system("cls");

	std::cout << "Type: Rectangle" << std::endl;
	Shape::outputColor();
	std::cout << "Area: " << getArea() << std::endl;

	int frameWidth = static_cast<int>(std::ceil(getWidth()));
	int frameHeight = static_cast<int>(std::ceil(height));

	std::cout << "Frame: " << frameWidth << 'x' << frameHeight << std::endl;
}

double Rectangle::getArea() { return getWidth() * height; }
