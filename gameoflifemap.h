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


    // pytanie: lepiej tu, czy w klasie Board?
    void forEachElement(std::function<void(Board &thisBoard, Point point)> myFcn);
    void forEachElement(std::function<void(Board &thisBoard, Point point)> myFcn1, std::function<void()> myFcn2);
};

#endif // GAMEOFLIFEMAP_H
