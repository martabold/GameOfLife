#include "UserCommands.hpp"
#include <iostream>

std::string UserCommands::next_command()
{
    std::string users_choice;

    std::string info = "Hello User! Please make one of the following moves:";
    int lenght = info.size() + 5;
    std::string line (lenght, '*');
    std::string frame = "\n" + line + "\n";
    frame += info + "\n";
    frame += line;
    std::cout << frame << std::endl;

    std::string next_move = "To make the next round, please press 1";
    std::string making_choice = "To make your choice, please press 2";
    std::string quitting = "To quit, please press 3";
    std::cout << next_move << std::endl;
    std::cout << making_choice << std::endl;
    std::cout << quitting << std::endl;
    std::cout << "Your choice is: ";
    std::cin >> users_choice;

    if(users_choice == "1")
    {
        return "next";
    }
    if(users_choice == "2")
    {
        return "choice";
    }
    if(users_choice == "3")
    {
        return "quit";
    }

    return "n";

}