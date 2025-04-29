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

    vector<States*> generateNeighbours(States* current);
    
    
    
    public:
    AStar();
    ~AStar();
    void Solve(States* startState);
};

void AStar::Solve(States* startState){
    pq.push(startState);
    while(!pq.empty()){
        States* current = pq.top();
        pq.pop();
        if(current->isGoal()){
            return;
        }
        else {
            current->setVisited();
        }
        vector <States*>neighbours=generateNeighbours(current);
        
    }
};

vector<States*> States::generateNeighbours(States* current){

}


#endif