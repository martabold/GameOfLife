#pragma once
#include <iostream>
#include "GameOfLifeGrid.hpp"
#include "CommandSource.hpp"


class GameOfLifeController
{
    GameOfLifeGrid &grid;
    

    public:
    //void changingRounds();
    GameOfLifeController(GameOfLifeGrid &grid);
    void play(CommandSource &command_source);
};