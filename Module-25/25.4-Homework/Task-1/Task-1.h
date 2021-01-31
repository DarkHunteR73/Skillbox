#pragma once

#include <iostream>

#include "point.h"

void scalpel(Point& a, Point& b) {
  std::cout << "Enter coordinates of begin: ";
  a = getPoint();
  std::cout << "Enter coordinates of end: ";
  b = getPoint();
  std::cout << "Cut made from point [" << a.x << ';' << a.y << "] to point ["
            << b.x << ';' << b.y << "]" << std::endl;
}

void suture(Point& a, Point& b) {
  std::cout << "Enter coordinates of begin: ";
  a = getPoint();
  std::cout << "Enter coordinates of end: ";
  b = getPoint();
  std::cout << "Suture made from point [" << a.x << ';' << a.y << "] to point ["
            << b.x << ';' << b.y << "]" << std::endl;
}

void hemostat() {
  std::cout << "Enter coordinates of hemostat: ";
  Point res;
  res = getPoint();
  std::cout << "Hemostat is installed at point [" << res.x << ';' << res.y
            << "]." << std::endl;
}

void tweezers() {
  std::cout << "Enter coordinates for tweezers: ";
  Point res;
  res = getPoint();
  std::cout << "Tweezers for point [" << res.x << ';' << res.y << "]."
            << std::endl;
}

void getCommand(std::string& _command) {
  std::cout << "Enter command: ";
  std::cin >> _command;
}