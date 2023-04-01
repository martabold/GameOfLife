#include "BoardTypeTorus.hpp"

int GameOfLifeGrid::countNeighbours(int row, int col) const  //metoda liczaca sasiadow komorki
{
    int cell_counter = 0;

    if(conditionOffTheGrid(row, col))
    {
        return -1;
    }
    else
    {
        for(int i = row - 1; i<= row +1; i++)
        {
            for(int j = col -1; j <= col +1; j++)
            {
                if(i != row || j != col)
                {
                    int x = i % height;
                    int y = j % width;

                    if(board[x + y * height].alive == true)
                    //       i % height + j % width * height 
                    {
                        cell_counter++;
                    }
                }
            }
        }
    }
    return cell_counter;
}
