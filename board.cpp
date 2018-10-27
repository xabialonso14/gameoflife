#include "board.h"

Board::Board()
{

}

void Board::setDimensions(uint8_t rows, uint8_t columns)
{
    // assign board dimensions properties
    this->rows = rows;
    this->columns = columns;

    // resize board
    boardElements.resize(rows);
    for(uint8_t i = 0; i < rows; i++)
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

int Board::getColumns() const
{
    return columns;
}

int Board::getRows() const
{
    return rows;
}

BoardElement* Board::elementAt(Point point)
{
    BoardElement* element = &(this->boardElements[point.row][point.column]);
    return element;
}

void Board::forEachElement(std::function<void (BoardElement* element, Point point)> elementAction)
{
  int rows = this->getRows();
  int columns = this->getColumns();

  for(uint8_t row=0;row<rows;row++)
  {
      for(uint8_t column=0;column<columns;column++)
      {
          // perform function with row, column and board parameters
          Point point = {row,column};
          elementAction(elementAt(point), point);
      }
  }
}
