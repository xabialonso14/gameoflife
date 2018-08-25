#include "board.h"

// komentarz: domyślny konstruktor jest generowany przez kompilator,
// jeśli nic w nim nie robisz, nie trzeba go dodawać; sugestia: może
// dodać
Board::Board()
{

}

void Board::setDimensions(int rows, int columns)
{
    // assign board dimensions properties
    setHeight(rows);
    setWidth(columns);

    // resize board
    boardElements.resize(height);
    for(int i = 0; i < height; ++i)
    {
      boardElements[i].resize(width);
    }
}

void Board::setWidth(int width)
{
    this->width = width;
}

void Board::setHeight(int height)
{
    this->height = height;
}

int Board::getWidth()
{
    return width;
}

int Board::getHeight()
{
    return height;
}





