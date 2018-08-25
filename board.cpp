#include "board.h"

// x is the column, y is the row. The origin (0,0) is top-left.
void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

// komentarz: domyślny konstruktor jest generowany przez kompilator,
// jeśli nic w nim nie robisz, nie trzeba go dodawać; sugestia: może
// dodać

// komentarz: znowu x/y, a potem width/height
void Board::setDimensions (int x, int y)
{
  // assign board dimensions properties
  height= x;
  width = y;

  // resize board
  boardElements.resize(height);
  for(int i = 0; i < height; ++i)
  {
    boardElements[i].resize(width);
  }
}

void Board::initMap()
{
	// komentarz: to wszystko powinno być ukryte w nowej abstrakcji
	// zeby nie trzeba było za każdym razem dwóch pętli robić
  for(int i=0;i<height;i++)
  {
      for(int j=0;j<width;j++)
      {
          // display current cell sign
          std::cout << ' ' << boardElements[i][j].sign;
      }

      // end of the row
      std::cout << std::endl;
  }

}


void Board::displayMap()
{
	// komentarz: width/height, x/y, row/columns - trzeba wybrać jedno i tego się trzymać
  for(int i=0;i<height;i++)
  {
      for(int j=0;j<width;j++)
	  {
		  // komentarz: te dwie pętle się często powtarzają - duplikacja kodu
          if (boardElements[i][j].sign == boardElements[i][j].nextSign)
          {
              boardElements[i][j].alive = boardElements[i][j].nextAlive;
              continue;
          }

          // if next sign is different than the current one, overwrite it
          setCursorPosition(j*2+1, i);
          std::cout << boardElements[i][j].nextSign;

          // update current cell properties
          boardElements[i][j].alive = boardElements[i][j].nextAlive;
          boardElements[i][j].sign = boardElements[i][j].nextSign;
      }
  }

  // after board update, set cursor position to the end
  setCursorPosition(0,height);
}


// komentarz: trochę dziwna, niewiele mówiąca nazwa
void Board::checkMap()
{
  for(int i=0;i<height;i++)
  {
      for(int j=0;j<width;j++)
      {
          // count cell neighbours
          boardElements[i][j].numberOfNeighbours = Board::countNeighbours(i,j);

          // if cell is currently alive
          if (boardElements[i][j].alive)
          {
              // if cell has too few or too many neighbours, it dies
              if ( boardElements[i][j].numberOfNeighbours < 2 || boardElements[i][j].numberOfNeighbours > 3 )
              {
                  boardElements[i][j].nextAlive = false;
                  boardElements[i][j].nextSign = '|';
              }
          }

          // otherwise, if cell is currently dead
          else
          {
              // if cell has exactly 3 neighbours, it becomes alive
              if ( 3==boardElements[i][j].numberOfNeighbours  )
              {
                  boardElements[i][j].nextAlive = true;
                  boardElements[i][j].nextSign = 'X';
              }
          }
      }
  }

}

int Board::countNeighbours(int x, int y)
{
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
                    if (true == boardElements[i][j].alive)
                    {
                        n++;
                    }
                }
            }
        }
    }

    // if current cell is alive, decrement n
    if (boardElements[x][y].alive)
        n--;

    return n;
}

void Board::addGlider(int x,int y)
{
    boardElements[x+0][y+1].sign = 'X';
    boardElements[x+1][y+2].sign = 'X';
    boardElements[x+2][y+0].sign = 'X';
    boardElements[x+2][y+1].sign = 'X';
    boardElements[x+2][y+2].sign = 'X';

    boardElements[x+0][y+1].nextSign = 'X';
    boardElements[x+1][y+2].nextSign = 'X';
    boardElements[x+2][y+0].nextSign = 'X';
    boardElements[x+2][y+1].nextSign = 'X';
    boardElements[x+2][y+2].nextSign = 'X';

    boardElements[x+0][y+1].alive = true;
    boardElements[x+1][y+2].alive = true;
    boardElements[x+2][y+0].alive = true;
    boardElements[x+2][y+1].alive = true;
    boardElements[x+2][y+2].alive = true;

    boardElements[x+0][y+1].nextAlive = true;
    boardElements[x+1][y+2].nextAlive = true;
    boardElements[x+2][y+0].nextAlive = true;
    boardElements[x+2][y+1].nextAlive = true;
    boardElements[x+2][y+2].nextAlive = true;
}

void Board::addDakota(int x,int y)
{
    boardElements[x+0][y+1].sign = 'X';
    boardElements[x+0][y+4].sign = 'X';
    boardElements[x+1][y+0].sign = 'X';
    boardElements[x+2][y+0].sign = 'X';
    boardElements[x+2][y+4].sign = 'X';
    boardElements[x+3][y+0].sign = 'X';
    boardElements[x+3][y+1].sign = 'X';
    boardElements[x+3][y+2].sign = 'X';
    boardElements[x+3][y+3].sign = 'X';

    boardElements[x+0][y+1].nextSign = 'X';
    boardElements[x+0][y+4].nextSign = 'X';
    boardElements[x+1][y+0].nextSign = 'X';
    boardElements[x+2][y+0].nextSign = 'X';
    boardElements[x+2][y+4].nextSign = 'X';
    boardElements[x+3][y+0].nextSign = 'X';
    boardElements[x+3][y+1].nextSign = 'X';
    boardElements[x+3][y+2].nextSign = 'X';
    boardElements[x+3][y+3].nextSign = 'X';

    boardElements[x+0][y+1].alive = true;
    boardElements[x+0][y+4].alive = true;
    boardElements[x+1][y+0].alive = true;
    boardElements[x+2][y+0].alive = true;
    boardElements[x+2][y+4].alive = true;
    boardElements[x+3][y+0].alive = true;
    boardElements[x+3][y+1].alive = true;
    boardElements[x+3][y+2].alive = true;
    boardElements[x+3][y+3].alive = true;

    boardElements[x+0][y+1].nextAlive = true;
    boardElements[x+0][y+4].nextAlive = true;
    boardElements[x+1][y+0].nextAlive = true;
    boardElements[x+2][y+0].nextAlive = true;
    boardElements[x+2][y+4].nextAlive = true;
    boardElements[x+3][y+0].nextAlive = true;
    boardElements[x+3][y+1].nextAlive = true;
    boardElements[x+3][y+2].nextAlive = true;
    boardElements[x+3][y+3].nextAlive = true;
}



