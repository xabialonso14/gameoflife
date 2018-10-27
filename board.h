#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <functional>
#include "boardelement.h"
#include "point.h"
#include "mysharedlib_global.h"

class MYSHAREDLIB_EXPORT Board
{
    private:
        int rows, columns;

    public:
        Board();

        void setDimensions(uint8_t rows, uint8_t columns);

        void setRows(int rows);
        void setColumns(int columns);

        int getRows() const;
        int getColumns() const;

        BoardElement* elementAt(Point point);
        void forEachElement(std::function<void(BoardElement* element, Point point)> elementAction);

        std::vector< std::vector<BoardElement> > boardElements;
};

#endif // BOARD_H
