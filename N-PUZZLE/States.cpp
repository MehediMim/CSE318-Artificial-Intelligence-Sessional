#ifndef STATES_H
#define STATES_H

#include <bits/stdc++.h>
using namespace std;

 
class States
{
private:

    vector<vector<int>>grid;
    States* parent;
    int move;

    // bool isVisited=false;


    
public:
    States(int k);
    ~States();

    vector<vector<int>> getGrid();
    void setGrid(vector<vector<int>> grid);

    States* getParent();
    void setParent(States* parent);

    void setVisited();
    bool getVisited();

    void setMove(int move);
    int getMove();
};

States::States(int k)
{
    parent=nullptr;
    grid.resize(k, vector<int>(k, 0));
    move=0;
    
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


// void States::setVisited(){
//     this->isVisited=true;
// }

// bool States::getVisited(){
//     return isVisited;
// }

void States::setMove(int move){
    this->move=move;
}

int States::getMove(){
    // return this->move;
    // while(parent!=nullptr){
    //     move++;
    //     parent=parent->getParent();
    // }
    return move;
}



#endif