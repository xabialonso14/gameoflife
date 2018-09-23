#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <functional>
#include "boardelement.h"
#include "point.h"

class Board
{
    private:
        int rows, columns;

    public:
        Board();

        void setDimensions(int rows, int columns);

        void setRows(int rows);
        void setColumns(int columns);

        const int getRows();
        const int getColumns();

        BoardElement* elementAt(Point point);
        void forEachElement(std::function<void(BoardElement* nextElement, Point point)> elementAction);

        std::vector< std::vector<BoardElement> > boardElements;
};

#endif // BOARD_H
