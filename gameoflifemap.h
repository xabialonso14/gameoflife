#ifndef GAMEOFLIFEMAP_H
#define GAMEOFLIFEMAP_H

#include "board.h"

class GameOfLifeMap
{

public:
    GameOfLifeMap();

    Board board;

    // komentarz: brak nazw zmiennych
    void setDimensions (int,int);
    void initMap();
    void displayMap();
    void checkMap();

    // komentarz: x,y -> Point
    int countNeighbours(int,int);
    void addGlider(int,int);
    void addDakota(int,int);
};

#endif // GAMEOFLIFEMAP_H
