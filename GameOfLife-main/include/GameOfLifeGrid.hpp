#pragma once
#include <vector>
#include <string>

struct Cell
{
    bool alive;
    bool nextRound;

    //bool isItAlive();
};

class GameOfLifeGrid
{


    public:
    GameOfLifeGrid(int width, int height); //konstruktor 
    void display() const; //wyswietla
    int getGridWidth() const;
    int getGridHeight() const;
    void changingCells(int row, int col);
    void cellsPlacementInTheNextRound(int row, int col);
    void makingChoices();
    virtual int countNeighbours(int row, int col) const;
    

    
    
    
    private:
    int conditionOffTheGrid(int row, int col) const;
    //int countNeighbours(int row, int col) const;
    bool verifyCells(int row, int col);
    
   
    //int countNeighboursTorus(int row, int col) const;
  
    int width;
    int height;
    std::vector<Cell> board;
    Cell& cartesianIntoElements(int row, int col);
    const Cell& cartesianIntoElements(int row, int col) const;
 

};

