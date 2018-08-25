#include "gameoflifemap.h"

GameOfLifeMap::GameOfLifeMap()
{

}

// komentarz: znowu x/y, a potem width/height
void GameOfLifeMap::setDimensions (int x, int y)
{
  board.setDimensions(x,y);

}

void GameOfLifeMap::initMap()
{
    int height = board.getHeight();
    int width = board.getWidth();


    // komentarz: to wszystko powinno być ukryte w nowej abstrakcji
    // zeby nie trzeba było za każdym razem dwóch pętli robić
  for(int i=0;i<height;i++)
  {
      for(int j=0;j<width;j++)
      {
          // display current cell sign
          std::cout << ' ' << board.boardElements[i][j].sign;
      }

      // end of the row
      std::cout << std::endl;
  }

}


void GameOfLifeMap::displayMap()
{
    int height = board.getHeight();
    int width = board.getWidth();

    // komentarz: width/height, x/y, row/columns - trzeba wybrać jedno i tego się trzymać
  for(int i=0;i<height;i++)
  {
      for(int j=0;j<width;j++)
      {
          // komentarz: te dwie pętle się często powtarzają - duplikacja kodu
          // display current cell sign
          std::cout << ' ' << board.boardElements[i][j].nextSign;

          // update current cell properties
          board.boardElements[i][j].alive = board.boardElements[i][j].nextAlive;
          board.boardElements[i][j].sign = board.boardElements[i][j].nextSign;
      }
      // end of the row
      std::cout << std::endl;
  }

}


// komentarz: trochę dziwna, niewiele mówiąca nazwa
void GameOfLifeMap::checkMap()
{

    int height = board.getHeight();
    int width = board.getWidth();

  for(int i=0;i<height;i++)
  {
      for(int j=0;j<width;j++)
      {
          // count cell neighbours
          board.boardElements[i][j].numberOfNeighbours = GameOfLifeMap::countNeighbours(i,j);

          // if cell is currently alive
          if (board.boardElements[i][j].alive)
          {
              // if cell has too few or too many neighbours, it dies
              if ( board.boardElements[i][j].numberOfNeighbours < 2 || board.boardElements[i][j].numberOfNeighbours > 3 )
              {
                  board.boardElements[i][j].nextAlive = false;
                  board.boardElements[i][j].nextSign = '|';
              }
          }

          // otherwise, if cell is currently dead
          else
          {
              // if cell has exactly 3 neighbours, it becomes alive
              if ( 3==board.boardElements[i][j].numberOfNeighbours  )
              {
                  board.boardElements[i][j].nextAlive = true;
                  board.boardElements[i][j].nextSign = 'X';
              }
          }
      }
  }

}

int GameOfLifeMap::countNeighbours(int x, int y)
{


    int height = board.getHeight();
    int width = board.getWidth();

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
                    if (true == board.boardElements[i][j].alive)
                    {
                        n++;
                    }
                }
            }
        }
    }

    // if current cell is alive, decrement n
    if (board.boardElements[x][y].alive)
        n--;

    return n;
}

void GameOfLifeMap::addGlider(int x,int y)
{
    board.boardElements[x+0][y+1].sign = 'X';
    board.boardElements[x+1][y+2].sign = 'X';
    board.boardElements[x+2][y+0].sign = 'X';
    board.boardElements[x+2][y+1].sign = 'X';
    board.boardElements[x+2][y+2].sign = 'X';

    board.boardElements[x+0][y+1].nextSign = 'X';
    board.boardElements[x+1][y+2].nextSign = 'X';
    board.boardElements[x+2][y+0].nextSign = 'X';
    board.boardElements[x+2][y+1].nextSign = 'X';
    board.boardElements[x+2][y+2].nextSign = 'X';

    board.boardElements[x+0][y+1].alive = true;
    board.boardElements[x+1][y+2].alive = true;
    board.boardElements[x+2][y+0].alive = true;
    board.boardElements[x+2][y+1].alive = true;
    board.boardElements[x+2][y+2].alive = true;

    board.boardElements[x+0][y+1].nextAlive = true;
    board.boardElements[x+1][y+2].nextAlive = true;
    board.boardElements[x+2][y+0].nextAlive = true;
    board.boardElements[x+2][y+1].nextAlive = true;
    board.boardElements[x+2][y+2].nextAlive = true;
}

void GameOfLifeMap::addDakota(int x,int y)
{
    board.boardElements[x+0][y+1].sign = 'X';
    board.boardElements[x+0][y+4].sign = 'X';
    board.boardElements[x+1][y+0].sign = 'X';
    board.boardElements[x+2][y+0].sign = 'X';
    board.boardElements[x+2][y+4].sign = 'X';
    board.boardElements[x+3][y+0].sign = 'X';
    board.boardElements[x+3][y+1].sign = 'X';
    board.boardElements[x+3][y+2].sign = 'X';
    board.boardElements[x+3][y+3].sign = 'X';

    board.boardElements[x+0][y+1].nextSign = 'X';
    board.boardElements[x+0][y+4].nextSign = 'X';
    board.boardElements[x+1][y+0].nextSign = 'X';
    board.boardElements[x+2][y+0].nextSign = 'X';
    board.boardElements[x+2][y+4].nextSign = 'X';
    board.boardElements[x+3][y+0].nextSign = 'X';
    board.boardElements[x+3][y+1].nextSign = 'X';
    board.boardElements[x+3][y+2].nextSign = 'X';
    board.boardElements[x+3][y+3].nextSign = 'X';

    board.boardElements[x+0][y+1].alive = true;
    board.boardElements[x+0][y+4].alive = true;
    board.boardElements[x+1][y+0].alive = true;
    board.boardElements[x+2][y+0].alive = true;
    board.boardElements[x+2][y+4].alive = true;
    board.boardElements[x+3][y+0].alive = true;
    board.boardElements[x+3][y+1].alive = true;
    board.boardElements[x+3][y+2].alive = true;
    board.boardElements[x+3][y+3].alive = true;

    board.boardElements[x+0][y+1].nextAlive = true;
    board.boardElements[x+0][y+4].nextAlive = true;
    board.boardElements[x+1][y+0].nextAlive = true;
    board.boardElements[x+2][y+0].nextAlive = true;
    board.boardElements[x+2][y+4].nextAlive = true;
    board.boardElements[x+3][y+0].nextAlive = true;
    board.boardElements[x+3][y+1].nextAlive = true;
    board.boardElements[x+3][y+2].nextAlive = true;
    board.boardElements[x+3][y+3].nextAlive = true;
}
