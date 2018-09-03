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
    for(int row = point.row-1; row < point.row+2; row++)
    {
        // check if rows are in the board
        if (row > -1 && row < rows)
        {
            // iterate over columns
            for(int column=point.column-1; column<point.column+2; column++)
            {
                // check if columns are in the board
                if (column > -1 && column < columns)
                {
                    // if board element is alive, increment n
                    if (true == board.boardElements[row][column].getAlive())
                    {
                        n++;
                    }
                }
            }
        }
    }

    // if current cell is alive, decrement n
    if (board.boardElements[point.row][point.column].getAlive())
        n--;

    return n;
}
