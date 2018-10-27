#include "positioninspector.h"

PositionInspector::PositionInspector()
{

}

int PositionInspector::countNeighbours(Board board, Point point)
{
    int rows = board.getRows();
    int columns = board.getColumns();

    // init number of neighbours to 0
    int n = 0;

    // iterate over rows
    for(uint8_t row = point.row > 0 ? point.row - 1 : 0; row < point.row + 2; row++)
    {
        // check if rows are in the board
        if (row < rows)
        {
            // iterate over columns
            for(uint8_t column = point.column > 0 ? point.column - 1 : 0; column < point.column + 2; column++)
            {
                // check if columns are in the board
                if (column < columns)
                {
                    // if board element is alive, increment n
                    if ( true == board.elementAt({row,column})->getAlive() )
                    {
                        n++;
                    }
                }
            }
        }
    }

    // if current cell is alive, decrement n
    if ( board.elementAt(point)->getAlive() )
        n--;

    return n;
}
