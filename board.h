#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include "boardelement.h"

struct Point
{
  int row;
  int column;
};

class Board
{
    private:
        int rows, columns;

    public:
        Board();

        void setDimensions(int rows, int columns);

        void setRows(int rows);
        void setColumns(int columns);

        int getRows();
        int getColumns();

        std::vector< std::vector<BoardElement> > boardElements;
};

#endif // BOARD_H
