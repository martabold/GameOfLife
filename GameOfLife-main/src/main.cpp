#include "GameOfLifeGrid.hpp"
#include "GameOfLifeController.hpp"
#include "AlwaysNextTurn.hpp"
#include "UserCommands.hpp"
#include "CommandSource.hpp"
#include "BoardTypeCylinder.hpp"
#include "BoardTypeTorus.hpp"

#include <iostream>

int main()
{
    
    AlwaysNextTurn auto_command_source;
    UserCommands user_command_source;
    GameOfLifeGrid grid{20,20};
    GameOfLifeController game{grid};

    std::string wybrany_tryb;
    std::cout << "(Select command source [user, auto]) Wybierz zrodlo komend [user, auto]: ";
    std::cin >> wybrany_tryb;

    if(wybrany_tryb == "user")
    {
        game.play(user_command_source);
    }
        
    else if (wybrany_tryb == "auto")
    {
        game.play(auto_command_source);
    }
        

    return 0;
    
}