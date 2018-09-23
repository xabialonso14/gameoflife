#include "board.h"

Board::Board()
{

}

void Board::setDimensions(int rows, int columns)
{
    // assign board dimensions properties
    this->rows = rows;
    this->columns = columns;

    // resize board
    boardElements.resize(rows);
    for(int i = 0; i < rows; ++i)
    {
      boardElements[i].resize(columns);
    }
}

void Board::setColumns(int columns)
{
    this->columns = columns;
}

void Board::setRows(int rows)
{
    this->rows = rows;
}

const int Board::getColumns()
{
    return columns;
}

const int Board::getRows()
{
    return rows;
}

BoardElement* Board::elementAt(Point point)
{
    BoardElement* element = &(this->boardElements[point.row][point.column]);
    return element;
}

void Board::forEachElement(std::function<void (BoardElement* nextElement, Point point)> elementAction)
{
  int rows = this->getRows();
  int columns = this->getColumns();

  for(int row=0;row<rows;row++)
  {
      for(int column=0;column<columns;column++)
      {
          // perform function with row, column and board parameters
          Point point = {row,column};
          BoardElement* element = &(this->boardElements[point.row][point.column]);
          elementAction(element, point);
      }
  }
}
