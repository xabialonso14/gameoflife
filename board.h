#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <windows.h>
#include "boardelement.h"

#pragma comment(lib, "user32")


// komentarz: Board powinien być czymś, co abstrachuje dwuwymiarową tablicę (boardElements);
// ta klasa powinna bardziej nazywać się GameOfLifeMap
class Board
{
    int width, height;

    public:
        Board();
		// komentarz: brak nazw zmiennych
        void setDimensions (int,int);
        void initMap();
        void displayMap();
        void checkMap();

		// komentarz: x,y -> Point
        int countNeighbours(int,int);
        void addGlider(int,int);
        void addDakota(int,int);
        std::vector< std::vector<BoardElement> > boardElements;
};

#endif // BOARD_H
