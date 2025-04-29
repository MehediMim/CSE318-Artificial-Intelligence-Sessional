#ifndef ASTAR_H
#define ASTAR_H

#include <bits/stdc++.h>
#include "States.cpp"
#include "heuristicFunction.cpp"
using namespace std;

class AStar
{
private:
    function<double(vector<vector<int>>)> hFN;

    struct comparator
    {
        AStar* astar;
        comparator(AStar*  astar):astar(astar){}
        bool operator()(States *const &s1, States *const &s2)
        {
            double h1=astar->hFN(s1->getGrid());
            double h2=astar->hFN(s2->getGrid());
            return h1>h2;
        }
    };

    priority_queue<States *, vector<States *>, comparator> pq;
    States* startState;
    States* goalState;
    
    bool isSolvable(States* startState);
    bool isGoal(States *state);
    vector<States*> generateNeighbours(States* current);
    States* Solve();

    int move=0;

    void printGrid(vector<vector<int>>grid);

    
    
    
public:
    AStar(States *startState){
        this->startState=startState;
    };

    void solvePath();
};


bool AStar::isGoal(States *state){
    vector<vector<int>> v= state->getGrid();
    int k=v.size();
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            int goal=k*i+(j+1);
            if(v[i][j]!=goal)return 0;
        }
    }
    return 1;
}

States* AStar::Solve(){
    pq.push(startState);
    while(!pq.empty()){
        States* current = pq.top();
        pq.pop();
        if(isGoal(current)){
            return current;
        }
        else {
            current->setVisited();
        }
        vector <States*>neighbours=generateNeighbours(current);
        
        for(auto state : neighbours){
            if(!state->getVisited()){
                pq.push(state);
            }
        }
        
    }
    return  nullptr;
};

vector<States*> AStar::generateNeighbours(States* current){
    int z_x=-1;
    int z_y=-1;
    vector<vector<int>> currGrid = current->getGrid();
    int k=currGrid.size();
    vector<States*>statePacket;
    
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(currGrid[i][j]==0){
                z_x=i;
                z_y=j;
                break;
            }
        }
        if(z_x!=-1)break;
    }
    
    vector<pair<int,int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
    
    for(auto d:dir){
        if(z_x+d.first>=0 and z_x+d.first<k){
            if(z_y+d.second>=0 and z_y+d.second<k){
                vector<vector<int>>newGrid=currGrid;
                swap(newGrid[z_x][z_y],newGrid[z_x+d.first][z_y+d.second]);
                // newGrid[z_x+d.first][z_y+d.second]=0;
                States* newState=new States(k);
                newState->setGrid(newGrid);
                newState->setParent(current);
                statePacket.push_back(newState);
            }
        }
    }
    return statePacket;
}

bool AStar::isSolvable(States* startState){
    vector<int>flat;

    int k=startState->getGrid().size();
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(startState->getGrid()[i][j]!=0)flat.push_back(startState->getGrid()[i][j]);
        }
    }

    int z_x=-1;
    int z_y=-1;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(startState->getGrid()[i][j]==0){
                z_x=i;
                z_y=j;
                break;
            }
        }
        if(z_x!=-1)break;
    }

    int inversion=0;

    for(int i=0;i<flat.size();i++){
        for(int j=i+1;j<flat.size();j++){
            if(flat[j]<flat[i])inversion++;
        }
    }
    if(k%2!=0){
        if(inversion%2==0){
            return 1;
        }
    }
    else{
        if(inversion%2!=0){
            if((k-1-z_x) % 2 ==0) return 1;
        }
        if(inversion%2==0){
            if((k-1-z_x) % 2 !=0) return 1;
        }
    }
    return 0;

}

void AStar::solvePath(){
    if(!isSolvable(this->startState)){
        cout<<"Unsolvable puzzle"<<endl;
    }
    else{
        goalState=Solve();
    }
    
    States* temp=goalState;
    vector<States*>stateBox;
    while(temp->getParent()!=nullptr){
        stateBox.push_back(temp);
        move++;
        temp=temp->getParent();
    }
    stateBox.push_back(startState);

    reverse(stateBox.begin(),stateBox.end());

    cout<<"Minimum number of moves "<<move<<endl;

    for(States* st: stateBox){
        printGrid(st->getGrid());
        cout<<endl;
    }
    
}

void AStar::printGrid(vector<vector<int>>grid){
    int k=grid.size();
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}



#endif