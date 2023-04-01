#pragma once
#include "GameOfLifeGrid.hpp"

class BoardTypeTorus : public GameOfLifeGrid
{
    public:
    int countNeighbours(int row, int col) const override;
};