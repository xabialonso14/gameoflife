#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include "boardelement.h"

#pragma comment(lib, "user32")


// komentarz: Board powinien być czymś, co abstrachuje dwuwymiarową tablicę (boardElements);
// ta klasa powinna bardziej nazywać się GameOfLifeMap
class Board
{
    int width, height;

    public:
        Board();

        void setDimensions(int rows, int columns);

        void setWidth(int width);
        void setHeight(int height);

        int getWidth();
        int getHeight();

        std::vector< std::vector<BoardElement> > boardElements;
};

#endif // BOARD_H
