#ifndef SEMIGREEDY_H
#define SEMIGREEDY_H

#include <random>
#include "Graph.cpp"
#include <unordered_map>
#include <climits>

pair<unordered_set<int>,unordered_set<int>> semiGreedyMaxCut(Graph& g,double alpha){
    
    unordered_set<int>X;
    unordered_set<int>Y;
    unordered_set<int>assigned;
    
    Edge maxWeightEdge=g.getMaxWeight();
    
    X.insert(maxWeightEdge.u);
    Y.insert(maxWeightEdge.v);
    
    assigned.insert(maxWeightEdge.u);
    assigned.insert(maxWeightEdge.v);

    while(assigned.size()<g.getVertexCount()){
        vector<int>candidate;

        unordered_map<int,ll>sigmaX;
        unordered_map<int,ll>sigmaY;
        unordered_map<int,ll>greedyScore;

        ll wmin =LLONG_MAX;
        ll wmax =LLONG_MIN;

        for(int j=1;j<=g.getVertexCount();j++){
            if (assigned.count(j)){
                continue;
            }

            ll sX=g.sumWeightsBetween(j,Y);
            ll sY=g.sumWeightsBetween(j,X);
            ll gval=max(sX,sY);

            sigmaX[j]=sX;
            sigmaY[j]=sY;
            greedyScore[j]=gval;

            wmin=min(wmin,gval);
            wmax=max(wmax,gval);

            candidate.push_back(j);
        }

        double mu = wmin + alpha*(wmax-wmin);

        vector<int>RCL;
        for (auto v:candidate){
            if(greedyScore[v]>=mu){
                RCL.push_back(v);
            }
        }
        mt19937 gen(random_device{}());
        uniform_int_distribution <> dis(0,RCL.size()-1);
        int chosen = RCL[dis(gen)];

        if(sigmaX[chosen]>sigmaY[chosen]){
            X.insert(chosen);
        }
        else Y.insert(chosen);
        assigned.insert(chosen);

    }

    return {X,Y};    
}

#endif