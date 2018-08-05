#include <QCoreApplication>
#include <iostream>

#include <windows.h>
#pragma comment(lib, "user32")

// x is the column, y is the row. The origin (0,0) is top-left.
void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

class BoardElement
{
    public:
        int numberOfNeighbours = 0;

        bool alive = false;
        bool nextAlive = false;

        char sign = '|';
        char nextSign = '|';
};

class Board
{
    int width, height;

    public:
        std::vector< std::vector<BoardElement> > boardElements;
        void setDimensions (int,int);
        void initMap();
        void displayMap();
        void checkMap();
        int countNeighbours(int,int);
};

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
  for(int i=0;i<height;i++)
  {
      for(int j=0;j<width;j++)
      {
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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // make console full screen
    // why '::' in front of methods?
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

    // create an instance of Board
    Board MyMap;

    // set its dimensions to 50 rows and 100 columns
    MyMap.setDimensions(50,100);

    // add a glider
    MyMap.boardElements[0][1].sign = 'X';
    MyMap.boardElements[1][2].sign = 'X';
    MyMap.boardElements[2][0].sign = 'X';
    MyMap.boardElements[2][1].sign = 'X';
    MyMap.boardElements[2][2].sign = 'X';

    MyMap.boardElements[0][1].nextSign = 'X';
    MyMap.boardElements[1][2].nextSign = 'X';
    MyMap.boardElements[2][0].nextSign = 'X';
    MyMap.boardElements[2][1].nextSign = 'X';
    MyMap.boardElements[2][2].nextSign = 'X';

    MyMap.boardElements[0][1].alive = true;
    MyMap.boardElements[1][2].alive = true;
    MyMap.boardElements[2][0].alive = true;
    MyMap.boardElements[2][1].alive = true;
    MyMap.boardElements[2][2].alive = true;

    MyMap.boardElements[0][1].nextAlive = true;
    MyMap.boardElements[1][2].nextAlive = true;
    MyMap.boardElements[2][0].nextAlive = true;
    MyMap.boardElements[2][1].nextAlive = true;
    MyMap.boardElements[2][2].nextAlive = true;

    // display initial board
    MyMap.initMap();

    while(1)
    {
        // time delay
        Sleep(500);

        // calculate next board
        MyMap.checkMap();

        // display next board
        MyMap.displayMap();
    }

    return a.exec();
}



