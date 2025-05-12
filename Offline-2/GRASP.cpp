#ifndef GRASP_H
#define GRASP_H

#include "Graph.cpp"
#include "SemiGreedy.cpp"
#include "LocalSearch.cpp"
#include <tuple>

tuple<unordered_set<int>,unordered_set<int>,int> graspMaxCut(Graph& g,int iteration,double alpha){
    unordered_set<int>bestX;
    unordered_set<int>bestY;
    ll bestWeight=LLONG_MIN;
    int it=0;
    for(int i=0;i<iteration;i++){
        pair<unordered_set<int>,unordered_set<int>> XY=semiGreedyMaxCut(g,alpha);
        auto _XY=localSearchMaxCut(g,XY.first,XY.second);
        it+=get<2>(_XY);
        ll weight=g.getCutWeight(get<0>(_XY),get<1>(_XY));
        if(weight>bestWeight){
            bestWeight=weight;
            bestX=get<0>(_XY);
            bestY=get<1>(_XY);
        }

    }
    return {bestX,bestY,it/iteration};
}

#endif