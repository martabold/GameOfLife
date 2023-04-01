#pragma once
#include "GameOfLifeGrid.hpp"

class BoardTypeCylinder : public GameOfLifeGrid
{
   public: 
   int countNeighbours(int row, int col) const override;

};