#ifndef GREEDY_H
#define GREEDY_H

#include "Graph.cpp"

pair<unordered_set<int>,unordered_set<int>> greedyMaxCut(Graph& g){

    unordered_set<int>X;
    unordered_set<int>Y;
    unordered_set<int>assigned;
    
    Edge maxWeightEdge=g.getMaxWeight();
    
    X.insert(maxWeightEdge.u);
    Y.insert(maxWeightEdge.v);
    
    assigned.insert(maxWeightEdge.u);
    assigned.insert(maxWeightEdge.v);
    

    for(int j=1;j<=g.getVertexCount();j++){
        if (assigned.count(j)){
            continue;
        }

        // X.insert(j);
        // ll weightIfX=g.getCutWeight(X,Y);
        // X.erase(j);
        // Y.insert(j);
        // ll weightIfY=g.getCutWeight(X,Y);
        // Y.erase(j);

        ll weightIfX=g.sumWeightsBetween(j,Y);
        ll weightIfY=g.sumWeightsBetween(j,X);
        
        if(weightIfX>weightIfY){
            X.insert(j);
        }
        else{
            Y.insert(j);
        }
        assigned.insert(j);
    }
    return {X,Y};    
}

#endif