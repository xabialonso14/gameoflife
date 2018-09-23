#include "board.h"

// komentarz: domyślny konstruktor jest generowany przez kompilator,
// jeśli nic w nim nie robisz, nie trzeba go dodawać; sugestia: może
// dodać
// pytanie: czy powinienem? co z innymi konstruktorami?
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

int Board::getColumns()
{
    return columns;
}

int Board::getRows()
{
    return rows;
}

void Board::forEachElement(std::function<void (Point point)> elementAction)
{
  int rows = this->getRows();
  int columns = this->getColumns();

  for(int row=0;row<rows;row++)
  {
      for(int column=0;column<columns;column++)
      {
          // perform function with row, column and board parameters
          elementAction({row,column});
      }
  }
}

