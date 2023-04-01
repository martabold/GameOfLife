#include "GameOfLifeController.hpp"
#include <iostream>
#include <cstdlib>
#include <unistd.h>


GameOfLifeController::GameOfLifeController(GameOfLifeGrid &grid) : grid(grid) //konstruktor klasy GameOfLifeController
{

}

void GameOfLifeController::play(CommandSource &command_source)   //wszystkie mozliwosci dostepne w userze
{
    while(true)
    {
        std::string command = command_source.next_command();

        if(command == "quit")
        {
            return;
        }

        if(command == "next")
        {
            system("clear");
            grid.display();

            for(int col = 0; col < grid.getGridWidth(); col++)
            {
                for(int row = 0; row < grid.getGridHeight(); row++)
                {
                    grid.changingCells(row, col);
                }
            }

                for(int col = 0; col < grid.getGridWidth(); col++)
                {
                    for(int row = 0; row < grid.getGridHeight(); row++)
                    {
                        grid.cellsPlacementInTheNextRound(row, col);
                    }
                }
                sleep(1);
        }
        if(command == "choice")
        {
            grid.makingChoices();
            std::cout<< "\n\n\nThis is how your board looks like right now: " << std::endl;
            grid.display();
        }
    }
}