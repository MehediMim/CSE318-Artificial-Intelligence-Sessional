#ifndef RANDOMIZED_H
#define RANDOMIZED_H

#include <random>
#include "Graph.cpp"

double randomizedMaxCut(Graph& g,int iteration){
    mt19937 gen(random_device{}());
    uniform_real_distribution <> dis(0.0,1.0);
    double totalCutWeight=0.0;

    for(int i=0;i<iteration;i++){
        unordered_set<int>X;
        unordered_set<int>Y;
        for(int j=1;j<=g.getVertexCount();++j){
            if(dis(gen)>=.5){
                X.insert(j);
            }
            else {
                Y.insert(j);
            }
        }
        totalCutWeight+=g.getCutWeight(X,Y);
    }
    return totalCutWeight/iteration;
    
}

#endif