#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <windows.h>
#include "boardelement.h"

#pragma comment(lib, "user32")


class Board
{
    int width, height;

    public:
        Board();
        void setDimensions (int,int);
        void initMap();
        void displayMap();
        void checkMap();
        int countNeighbours(int,int);
        void addGlider(int,int);
        void addDakota(int,int);
        std::vector< std::vector<BoardElement> > boardElements;
};

#endif // BOARD_H
