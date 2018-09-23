#include "point.h"

Point Point::operator+(const Point& p)
{
     Point point;

     point.row = this->row + p.row;
     point.column = this->column + p.column;

     return point;
}
