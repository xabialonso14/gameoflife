#include "gameoflifemap.h"

GameOfLifeMap::GameOfLifeMap(int rows, int columns)
{
    board.setDimensions(rows,columns);
}

void GameOfLifeMap::displayMap()
{
    int height = board.getRows();
    int width = board.getColumns();


    // komentarz: to wszystko powinno być ukryte w nowej abstrakcji
    // zeby nie trzeba było za każdym razem dwóch pętli robić
  for(int i=0;i<height;i++)
  {
      for(int j=0;j<width;j++)
      {
          // display current cell sign
          std::cout << ' ' << board.boardElements[i][j].getSign();
      }

      // end of the row
      std::cout << std::endl;
  }

}

void GameOfLifeMap::updateMap()
{

    Board nextBoard = board;

    int rows = board.getRows();
    int columns = board.getColumns();

    for(int row=0;row<rows;row++)
    {
        for(int column=0;column<columns;column++)
        {
            // count cell neighbours
            board.boardElements[row][column].numberOfNeighbours = GameOfLifeMap::countNeighbours({row,column});

            // if cell is currently alive
            if (board.boardElements[row][column].getAlive())
            {
                // if cell has too few or too many neighbours, it dies
                if ( board.boardElements[row][column].numberOfNeighbours < 2 || board.boardElements[row][column].numberOfNeighbours > 3 )
                {
                    nextBoard.boardElements[row][column].setAlive(false);
                    nextBoard.boardElements[row][column].setSign('|');
                }
            }

            // otherwise, if cell is currently dead
            else
            {
                // if cell has exactly 3 neighbours, it becomes alive
                if ( 3==board.boardElements[row][column].numberOfNeighbours  )
                {
                    nextBoard.boardElements[row][column].setAlive(true);
                    nextBoard.boardElements[row][column].setSign('X');
                }
            }
        }
    }



//    std::function<void(int row, int column)> myFcn = [](int row, int column)
//    {

//    };

//    forEachElement([](int row, int column), board)
//    {

//    };

  board = nextBoard;
}

int GameOfLifeMap::countNeighbours(Point point)
{
    int height = board.getRows();
    int width = board.getColumns();

    int x = point.row;
    int y = point.column;

    // init number of neighbours to 0
    int n = 0;

    // iterate over rows
    for(int i=x-1;i<x+2;i++)
    {
        // check if rows are in the board
        if (i>-1 && i<height)
        {
            // iterate over columns
            for(int j=y-1;j<y+2;j++)
            {
                // check if columns are in the board
                if (j>-1 && j<width)
                {
                    // if board element is alive, increment n
                    if (true == board.boardElements[i][j].getAlive())
                    {
                        n++;
                    }
                }
            }
        }
    }

    // if current cell is alive, decrement n
    if (board.boardElements[x][y].getAlive())
        n--;

    return n;
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

void GameOfLifeMap::forEachElement(std::function<void (int row, int column)> myFcn, Board board)
{
  int rows = board.getRows();
  int columns = board.getColumns();

  for(int row=0;row<rows;row++)
  {
      for(int column=0;column<columns;column++)
      {
          // perform function with row and column parameters
          myFcn(row,column);
      }
  }
}
