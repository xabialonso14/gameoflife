#ifndef GAMEOFLIFEMAP_H
#define GAMEOFLIFEMAP_H

#include "board.h"
#include "positioninspector.h"

class GameOfLifeMap
{
private:
    Board board;

public:
    GameOfLifeMap(uint8_t rows, uint8_t columns);

    void displayMap();
    void updateMap();

    void addGlider(Point point);
    void addDakota(Point point);

};

#endif // GAMEOFLIFEMAP_H
