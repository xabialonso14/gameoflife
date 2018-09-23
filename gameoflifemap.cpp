#include "gameoflifemap.h"

GameOfLifeMap::GameOfLifeMap(int rows, int columns)
{
    board.setDimensions(rows,columns);
}

void GameOfLifeMap::displayMap()
{
    board.forEachElement([&](Point point)
    {
        // display current cell sign
        std::cout << ' ' << board.boardElements[point.row][point.column].getSign();

        if (board.getColumns() == point.column + 1)
        {
            std::cout << std::endl;
        }

    });

}

void GameOfLifeMap::updateMap()
{
    Board nextBoard = board;

    nextBoard.forEachElement([&](Point point)
    {
        // count cell neighbours
        board.boardElements[point.row][point.column].numberOfNeighbours = PositionInspector().countNeighbours(board,point);


        // if cell is currently alive
        if (board.boardElements[point.row][point.column].getAlive())
        {
            // if cell has too few or too many neighbours, it dies
            if ( board.boardElements[point.row][point.column].numberOfNeighbours < 2 || board.boardElements[point.row][point.column].numberOfNeighbours > 3 )
            {
                nextBoard.boardElements[point.row][point.column].setAlive(false);
                nextBoard.boardElements[point.row][point.column].setSign('|');
            }
        }

        // otherwise, if cell is currently dead
        else
        {
            // if cell has exactly 3 neighbours, it becomes alive
            if ( 3==board.boardElements[point.row][point.column].numberOfNeighbours  )
            {
                nextBoard.boardElements[point.row][point.column].setAlive(true);
                nextBoard.boardElements[point.row][point.column].setSign('X');
            }
        }

    });

    board = nextBoard;
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
