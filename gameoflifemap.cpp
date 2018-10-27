#include "gameoflifemap.h"

GameOfLifeMap::GameOfLifeMap(uint8_t rows, uint8_t columns)
{
    board.setDimensions(rows,columns);
}

void GameOfLifeMap::displayMap()
{
    board.forEachElement([&](BoardElement* element, Point point)
    {
        // display current cell sign
        std::cout << ' ' << element->getSign();

        if (board.getColumns() - 1 == point.column)
        {
            std::cout << std::endl;
        }
    });
}

void GameOfLifeMap::updateMap()
{
    Board nextBoard = board;

    nextBoard.forEachElement([&](BoardElement* nextElement, Point point)
    {
        // count cell neighbours
        int nNeighbours = PositionInspector().countNeighbours(board,point);

        // instantiate old boardElement
        BoardElement currentElement = board.boardElements[point.row][point.column];

        // if cell is currently alive and has too few/too many neighbours, it dies
        if  (currentElement.getAlive() && (nNeighbours < 2 || nNeighbours > 3) )
        {
            nextElement->setAlive(false);
            nextElement->setSign('|');
        }

        // otherwise, if cell is currently dead and has exactly 3 neighbours, it becomes alive
        else if ( !currentElement.getAlive() && (3 == nNeighbours) )
        {
            nextElement->setAlive(true);
            nextElement->setSign('X');
        }
    });

    board = nextBoard;
}

void GameOfLifeMap::addGlider(Point point)
{
    board.elementAt(point + Point{0,1})->setSign('X');
    board.elementAt(point + Point{1,2})->setSign('X');
    board.elementAt(point + Point{2,0})->setSign('X');
    board.elementAt(point + Point{2,1})->setSign('X');
    board.elementAt(point + Point{2,2})->setSign('X');

    board.elementAt(point + Point{0,1})->setAlive(true);
    board.elementAt(point + Point{1,2})->setAlive(true);
    board.elementAt(point + Point{2,0})->setAlive(true);
    board.elementAt(point + Point{2,1})->setAlive(true);
    board.elementAt(point + Point{2,2})->setAlive(true);
}

void GameOfLifeMap::addDakota(Point point)
{
    board.elementAt(point + Point{0,1})->setSign('X');
    board.elementAt(point + Point{0,4})->setSign('X');
    board.elementAt(point + Point{1,0})->setSign('X');
    board.elementAt(point + Point{2,0})->setSign('X');
    board.elementAt(point + Point{2,4})->setSign('X');
    board.elementAt(point + Point{3,0})->setSign('X');
    board.elementAt(point + Point{3,1})->setSign('X');
    board.elementAt(point + Point{3,2})->setSign('X');
    board.elementAt(point + Point{3,3})->setSign('X');

    board.elementAt(point + Point{0,1})->setAlive(true);
    board.elementAt(point + Point{0,4})->setAlive(true);
    board.elementAt(point + Point{1,0})->setAlive(true);
    board.elementAt(point + Point{2,0})->setAlive(true);
    board.elementAt(point + Point{2,4})->setAlive(true);
    board.elementAt(point + Point{3,0})->setAlive(true);
    board.elementAt(point + Point{3,1})->setAlive(true);
    board.elementAt(point + Point{3,2})->setAlive(true);
    board.elementAt(point + Point{3,3})->setAlive(true);
}
