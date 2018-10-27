#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Point
{
  uint8_t row;
  uint8_t column;

  Point operator+(const Point& p);
};

#endif // POINT_H
