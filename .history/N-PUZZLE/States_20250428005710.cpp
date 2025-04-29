#ifndef STATES_H
#define STATES_H

#include <bits/stdc++.h>
using namespace std;

 
class States
{
private:

    vector<vector<int>>grid;
    States* parent;
    bool isVisited;


    
public:
    States(int k);
    ~States();

    vector<vector<int>> getGrid();
    void setGrid(vector<vector<int>> grid);

    States* getParent();
    void setParent(States* parent);

    bool isGoal();

    void setVisited();
    bool getVisited();
};

States::States(int k)
{
    parent=nullptr;
    grid.resize(k, vector<int>(k, 0));
    
}

States::~States()
{
}


vector<vector<int>> States::getGrid(){
    return grid;
}

void States::setGrid(vector<vector<int>> grid){
    this->grid = grid;
}
States* States::getParent(){
    return parent;
}

void States::setParent(States* parent){
    this->parent=parent;
}

bool States::isGoal(){

}

void States::setVisited(){
    this->isVisited=true;
}




#endif