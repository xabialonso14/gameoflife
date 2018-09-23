#ifndef GAMEOFLIFEMAP_H
#define GAMEOFLIFEMAP_H

#include "board.h"
#include "positioninspector.h"

class GameOfLifeMap
{

public:
    GameOfLifeMap(int rows, int columns);

    Board board;

    void displayMap();
    void updateMap();

    void addGlider(Point point);
    void addDakota(Point point);

};

#endif // GAMEOFLIFEMAP_H
