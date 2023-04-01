#include "GameOfLifeGrid.hpp"
#include <iostream>
#include <random>
#include <string>

/*bool Cell::isItAlive()  //chcialam zrobic jakis getter, ale z tego zrezygnowalam
{
    return alive;
}*/


std::string debugDisplayGrid(const Cell &f)   //ustala znak dla zywej i martwej komorki
{
    std::string result;
    result += f.alive ? "*" : " ";

    return result;
}

GameOfLifeGrid::GameOfLifeGrid(int width, int height):  //konstruktor klasy GameOflifeGrid
width(width),
height(height),
board(width * height, Cell{false, false})
{

//sztywne ustawianie struktur w konstruktorze (+ moja jedna dodatkowa)

//toad
     cartesianIntoElements(6,5).alive = true;
     cartesianIntoElements(6,6).alive = true;
     cartesianIntoElements(6,4).alive = true;
     cartesianIntoElements(7,5).alive = true;
     cartesianIntoElements(7,4).alive = true;
     cartesianIntoElements(7,3).alive = true;

//block
    cartesianIntoElements(1,1).alive = true;
    cartesianIntoElements(1,2).alive = true;
    cartesianIntoElements(2,1).alive = true;
    cartesianIntoElements(2,2).alive = true;

//tub
    cartesianIntoElements(3,12).alive = true;
    cartesianIntoElements(4,11).alive = true;
    cartesianIntoElements(4,13).alive = true;
    cartesianIntoElements(5,12).alive = true;

//blinker
    cartesianIntoElements(3,17).alive = true;
    cartesianIntoElements(4,17).alive = true;
    cartesianIntoElements(5,17).alive = true;

//beacon
    cartesianIntoElements(17,17).alive = true;
    cartesianIntoElements(16,17).alive = true;
    cartesianIntoElements(17,16).alive = true;
    cartesianIntoElements(15,14).alive = true;
    cartesianIntoElements(14,14).alive = true;
    cartesianIntoElements(14,15).alive = true;

     

}

Cell& GameOfLifeGrid::cartesianIntoElements(int row, int col)  //zamiana wspolrzednych kartezjanskich na dany element macierzy
{
    return board.at(row + col * height);
}

const Cell& GameOfLifeGrid::cartesianIntoElements(int row, int col) const  //to samo ale dla funkcji constowej
{
    return board.at(row + col * height);
}

void GameOfLifeGrid::display() const  //wyswietla plansze - grida
{
        for(int row = 0; row < height; row++)
        {
            for(int col = 0; col < width; col++)
            {
                std::cout<<debugDisplayGrid(cartesianIntoElements(row, col));
            }
            std::cout<<std::endl;
        }
}

int GameOfLifeGrid::getGridWidth() const
{
        return width;
}

int GameOfLifeGrid::getGridHeight() const
{
        return height;
}

int GameOfLifeGrid::conditionOffTheGrid(int row, int col) const    //warunek ze komorka poza gridem
{
    return ((row < 0 || row >= height) || (col < 0 || col >= width));
}

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
                if((i != row || j != col) && (i >= 0 && i <= height -1) && (j >= 0 && j <= width -1))
                {
                    if(cartesianIntoElements(i,j).alive == true)
                    {
                        cell_counter++;
                    }
                }
            }
        }
    }
    return cell_counter;


}

bool GameOfLifeGrid::verifyCells(int row, int col)   //weryfikuje czy aby na pewno wszystko sie zgadza
{
    if(conditionOffTheGrid(row, col))
    {
        return false;
    }
    if(cartesianIntoElements(row, col).alive == true)
    {
        return true;
    }

    return false;
}

void GameOfLifeGrid::cellsPlacementInTheNextRound(int row, int col)    //wszystkie zasady co do zycia czy smierci komorki
{
    if(cartesianIntoElements(row, col).alive == true)
    {
        if(countNeighbours(row, col) == 2 || countNeighbours(row, col) == 3)
        {
            cartesianIntoElements(row, col).nextRound = false;
        }
        else //2< && >3
        {
            cartesianIntoElements(row, col).nextRound = true;
        }
    }
    else
    {
        if(countNeighbours(row, col) == 3)
        {
            cartesianIntoElements(row, col).nextRound = true;
        }
        else
        {
            cartesianIntoElements(row, col).nextRound = false;
        }
        
    }
}

void GameOfLifeGrid::changingCells(int row, int col)       //zamiana komorek zywa na martwa lub martwa na zywa
{
    if(cartesianIntoElements(row, col).nextRound == true)
    {
        if(cartesianIntoElements(row, col).alive == true)
        {
            cartesianIntoElements(row, col).alive = false;
        }
        else
        {
            cartesianIntoElements(row, col).alive = true;
        }
    }
    else
    {
        return;
    }
}


void GameOfLifeGrid::makingChoices()       //metoda do opcji "choice" w zdrodle komend user
{
    int row;
    int col;

    std::cout << "Choose a row in which you'd like to change a state of a cell: ";
    std::cin >> row;
    std::cout << "Choose a column in which you'd like to change a state of a cell: ";
    std::cin >> col;

    if(verifyCells(row, col) == true)
    {
        cartesianIntoElements(row, col).alive = false;
    }
    else
    {
        cartesianIntoElements(row, col).alive = true;
    }

}