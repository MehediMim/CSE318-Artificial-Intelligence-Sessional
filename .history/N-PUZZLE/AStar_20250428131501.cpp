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

    priority_queue<States *, vector<States *>, comparator> pq{comparator(this)};
    vector<vector<vector<int>>>visited;
    States* startState;
    States* goalState;
    
    bool isSolvable(States* startState);
    bool isGoal(States *state);
    vector<States*> generateNeighbours(States* current);
    States* Solve();

    int move=0;
    int stateExplored=0;
    int stateExpanded=0;

    void printGrid(vector<vector<int>> grid);
    bool isVisited(vector<vector<int>> grid);
    void printPQ() ;
    
    
    
public:
    AStar(States *startState,function<double(vector<vector<int>>)> hFN){
        this->hFN=hFN;
        this->startState=startState;
    };

    void solvePath();
};


bool AStar::isGoal(States *state){
    vector<vector<int>> v= state->getGrid();
    int k=v.size();
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            int goal;
            if(k-i==1 and k-j==1){
                goal=0;
            }
            else goal=k*i+(j+1);
            if(v[i][j]!=goal)return 0;
        }
    }
    return 1;
}

States* AStar::Solve(){
    pq.push(startState);
    while(!pq.empty()){
    // for(int i=0;i<20;i++){

        // cout<<i<<endl;
        // printPQ();


        States* current = pq.top();
        pq.pop();
        stateExplored++;
        if(isGoal(current)){
            return current;
        }
        else {
            // current->setVisited();
            visited.push_back(current->getGrid());
            
        }
        vector <States*>neighbours=generateNeighbours(current);
        
        for(auto state : neighbours){
            // if(!state->getVisited()){
            if(!isVisited(state->getGrid())){
                pq.push(state);
                visited.push_back(state->getGrid());
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
                
                stateExpanded++;
            }
        }
    }
    return statePacket;
}

bool AStar::isSolvable(States* startState){
    vector<int>flat;
    // cout<<"Line130"<<endl;
    int k=startState->getGrid().size();
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(startState->getGrid()[i][j]!=0)flat.push_back(startState->getGrid()[i][j]);
        }
    }
    
    // cout<<"Line138"<<endl;
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
    
    // cout<<"Line152"<<endl;
    int inversion=0;
    
    for(int i=0;i<flat.size();i++){
        for(int j=i+1;j<flat.size();j++){
            if(flat[j]<flat[i])inversion++;
        }
    }
    // cout<<"Line160"<<endl;
    if(k%2!=0){
        // cout<<"Line162"<<endl;
        cout<<inversion<<endl;
        if(inversion%2==0){
            cout<<inversion<<endl;
            return 1;
        }
    }
    else{
        // cout<<"Line168"<<endl;
        if(inversion%2!=0){
            if((k-1-z_x) % 2 ==0) return 1;
        }
        // cout<<"Line172"<<endl;
        if(inversion%2==0){
            if((k-1-z_x) % 2 !=0) return 1;
        }
    }
    // cout<<"Line177"<<endl;
    return 0;

}

void AStar::solvePath(){
    if(!isSolvable(this->startState)){
        cout<<"Unsolvable puzzle"<<endl;
        return;
    }
    else{
        // cout<<"Is solvable checking"<<endl;
        goalState=Solve();
        // cout<<"Is solvable checked"<<endl;
    }
    
    States* temp=goalState;
    vector<States*>stateBox;
    while(temp->getParent()!=nullptr){
        stateBox.push_back(temp);
        move++;
        temp=temp->getParent();
    }
    stateBox.push_back(startState);
    // cout<<"Path generated"<<endl;

    reverse(stateBox.begin(),stateBox.end());

    cout<<"Minimum number of moves "<<move<<endl;
    cout<<"State Explored "<<stateExplored<<endl;
    cout<<"State Expanded "<<stateExpanded<<endl;

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

bool AStar::isVisited(vector<vector<int>>grid){
    int k=grid.size();
    // bool _visited=false;
    for(auto gridInVisited : visited){
        bool vstd=true;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(grid[i][j]!=gridInVisited[i][j]){
                    vstd=false;
                    break;
                }
            }
        }
        if(vstd==true) return true;
    }
    return false;
}

void AStar::printPQ() {
    priority_queue<States*, vector<States*>, comparator> temp = pq; // 🛑 Make a copy

    cout << "Current Priority Queue:" << endl;

    while (!temp.empty()) {
        States* element = temp.top();
        temp.pop();

        printGrid(element->getGrid()); // your existing printGrid function
        cout << "----" << endl;
    }
}


#endif