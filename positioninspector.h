#ifndef POSITIONINSPECTOR_H
#define POSITIONINSPECTOR_H

#include "board.h"
#include "mysharedlib_global.h"

class MYSHAREDLIB_EXPORT PositionInspector
{
public:
    PositionInspector();

    int countNeighbours(Board board, Point point);
};

#endif // POSITIONINSPECTOR_H
