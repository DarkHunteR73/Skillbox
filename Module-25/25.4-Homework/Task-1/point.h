#pragma once

#include <iostream>
#include <string>

struct Point {
  double x = 0.0;
  double y = 0.0;
};

Point getPoint() {
  Point res;
  std::cin >> res.x >> res.y;
  return res;
}

bool isEqualPoints(Point& _scalpelA, Point& _scalpelB, Point& _sutureA,
                   Point& _sutureB) {
  return ((_scalpelA.x == _sutureA.x) && (_scalpelA.y == _sutureA.y) &&
          (_scalpelB.x == _sutureB.x) && (_scalpelB.y == _sutureB.y)) ||
         ((_scalpelA.x == _sutureB.x) && (_scalpelA.y == _sutureB.y) &&
          (_scalpelB.x == _sutureA.x) && (_scalpelB.y == _sutureA.y));
}