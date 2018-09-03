#include "gameoflifemap.h"

GameOfLifeMap::GameOfLifeMap(int rows, int columns)
{
    board.setDimensions(rows,columns);
}

void GameOfLifeMap::displayMap()
{
    forEachElement([](Board &thisBoard, Point point)
    {
        // display current cell sign
        std::cout << ' ' << thisBoard.boardElements[point.row][point.column].getSign();
    },[]()
    {
        std::cout << std::endl;
    });
}

void GameOfLifeMap::updateMap()
{
    forEachElement([](Board &thisBoard, Point point)
    {
        // count cell neighbours
        thisBoard.boardElements[point.row][point.column].numberOfNeighbours = PositionInspector().countNeighbours(thisBoard,point);
    });

    forEachElement([](Board &thisBoard, Point point)
    {
        // if cell is currently alive
        if (thisBoard.boardElements[point.row][point.column].getAlive())
        {
            // if cell has too few or too many neighbours, it dies
            if ( thisBoard.boardElements[point.row][point.column].numberOfNeighbours < 2 || thisBoard.boardElements[point.row][point.column].numberOfNeighbours > 3 )
            {
                thisBoard.boardElements[point.row][point.column].setAlive(false);
                thisBoard.boardElements[point.row][point.column].setSign('|');
            }
        }

        // otherwise, if cell is currently dead
        else
        {
            // if cell has exactly 3 neighbours, it becomes alive
            if ( 3==thisBoard.boardElements[point.row][point.column].numberOfNeighbours  )
            {
                thisBoard.boardElements[point.row][point.column].setAlive(true);
                thisBoard.boardElements[point.row][point.column].setSign('X');
            }
        }
    });
}

void GameOfLifeMap::addGlider(Point point)
{
    board.boardElements[point.row+0][point.column+1].setSign('X');
    board.boardElements[point.row+1][point.column+2].setSign('X');
    board.boardElements[point.row+2][point.column+0].setSign('X');
    board.boardElements[point.row+2][point.column+1].setSign('X');
    board.boardElements[point.row+2][point.column+2].setSign('X');

    board.boardElements[point.row+0][point.column+1].setAlive(true);
    board.boardElements[point.row+1][point.column+2].setAlive(true);
    board.boardElements[point.row+2][point.column+0].setAlive(true);
    board.boardElements[point.row+2][point.column+1].setAlive(true);
    board.boardElements[point.row+2][point.column+2].setAlive(true);
}

void GameOfLifeMap::addDakota(Point point)
{
    board.boardElements[point.row+0][point.column+1].setSign('X');
    board.boardElements[point.row+0][point.column+4].setSign('X');
    board.boardElements[point.row+1][point.column+0].setSign('X');
    board.boardElements[point.row+2][point.column+0].setSign('X');
    board.boardElements[point.row+2][point.column+4].setSign('X');
    board.boardElements[point.row+3][point.column+0].setSign('X');
    board.boardElements[point.row+3][point.column+1].setSign('X');
    board.boardElements[point.row+3][point.column+2].setSign('X');
    board.boardElements[point.row+3][point.column+3].setSign('X');

    board.boardElements[point.row+0][point.column+1].setAlive(true);
    board.boardElements[point.row+0][point.column+4].setAlive(true);
    board.boardElements[point.row+1][point.column+0].setAlive(true);
    board.boardElements[point.row+2][point.column+0].setAlive(true);
    board.boardElements[point.row+2][point.column+4].setAlive(true);
    board.boardElements[point.row+3][point.column+0].setAlive(true);
    board.boardElements[point.row+3][point.column+1].setAlive(true);
    board.boardElements[point.row+3][point.column+2].setAlive(true);
    board.boardElements[point.row+3][point.column+3].setAlive(true);
}


void GameOfLifeMap::forEachElement(std::function<void (Board &thisBoard, Point point)> myFcn)
{
  int rows = this->board.getRows();
  int columns = this->board.getColumns();

  for(int row=0;row<rows;row++)
  {
      for(int column=0;column<columns;column++)
      {
          // perform function with row, column and board parameters
          myFcn(this->board, {row,column});
      }
  }
}

void GameOfLifeMap::forEachElement(std::function<void (Board &thisBoard, Point point)> myFcn1, std::function<void ()> myFcn2)
{
  int rows = this->board.getRows();
  int columns = this->board.getColumns();

  for(int row=0;row<rows;row++)
  {
      for(int column=0;column<columns;column++)
      {
          // perform function with row, column and board parameters
          myFcn1(this->board, {row,column});
      }

      myFcn2();
  }
}
