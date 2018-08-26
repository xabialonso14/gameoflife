#ifndef GAMEOFLIFEMAP_H
#define GAMEOFLIFEMAP_H

#include <functional>
#include "board.h"

class GameOfLifeMap
{

public:
    GameOfLifeMap(int rows, int columns);

    Board board;

    void displayMap();
    void updateMap();

    int countNeighbours(Point point);
    void addGlider(Point point);
    void addDakota(Point point);

    // pytanie: lepiej tu, czy w klasie Board?
    void forEachElement(std::function<void(int row, int column)> myFcn, Board board);
};

#endif // GAMEOFLIFEMAP_H
