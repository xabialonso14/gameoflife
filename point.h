#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "mysharedlib_global.h"

struct MYSHAREDLIB_EXPORT Point
{
  uint8_t row;
  uint8_t column;

  Point operator+(const Point& p);
};

#endif // POINT_H
