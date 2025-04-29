#ifndef STATES_H
#define STATES_H

#include <bits/stdc++.h>
using namespace std;

 
class States
{
private:

    vector<vector<int>>grid;
    States* parent;

    
public:
    States(int k);
    ~States();

    vector<vector<int>> getGrid();
    void setGrid(vector<vector<int>> grid);
};

States::States(int k)
{
    parent=nullptr;
    grid.resize(k, vector<int>(k, 0));

}

vector<vector<int>> States::getGrid(){
    return grid;
}

void States::setGrid(vector<vector<int>> grid){
    this->grid = grid;
}

States::~States()
{
}



#endif