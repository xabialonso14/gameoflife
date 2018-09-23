#ifndef GAMEOFLIFEMAP_H
#define GAMEOFLIFEMAP_H

#include "board.h"
#include "positioninspector.h"

class GameOfLifeMap
{
private:
    Board board;

public:
    GameOfLifeMap(int rows, int columns);  

    const void displayMap();
    void updateMap();

    void addGlider(Point point);
    void addDakota(Point point);

};

#endif // GAMEOFLIFEMAP_H
