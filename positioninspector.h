#ifndef POSITIONINSPECTOR_H
#define POSITIONINSPECTOR_H

#include "board.h"

class PositionInspector
{
public:
    PositionInspector();

    int countNeighbours(Board board, Point point);
};

#endif // POSITIONINSPECTOR_H
