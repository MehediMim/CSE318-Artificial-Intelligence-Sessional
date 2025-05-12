#ifndef LOCALSEARCH_H
#define LOCALSEARCH_H

#include "Graph.cpp"
#include <climits>
#include <tuple>

tuple<unordered_set<int>, unordered_set<int>,int> localSearchMaxCut(Graph& g, unordered_set<int> X, unordered_set<int> Y){
    // vector<unordered_set<int>> adjacencyMatrix = g.getAdj();
    const auto& adjacencyMatrix = g.getAdj();
    bool improved = true;
    int iteration=0;
    while (improved){
        iteration++;    
        // cout<<"HELLO"<<endl;
        improved=false;
        // ll bestDelta=LLONG_MIN;
        ll bestDelta=0;
        int bestDeltavertex=-1;
        bool movefromX=false;

        for (int v = 1; v <= g.getVertexCount(); ++v){
            ll delta=0;
            ll internal = 0;
            ll external = 0;
            bool vInX = X.count(v);
            const unordered_set<int>& neighbour = adjacencyMatrix[v];

            for (auto u : neighbour){
                int w = g.getValueOfEdge(v, u);
                bool uInX = X.count(u);
                // if (vInX){
                //     if(uInX){
                //         internal+=w;
                //     }
                //     else {
                //         external+=w;
                //     }
                // }
                // else if(!vInX){
                //     if(!uInX){
                //         internal+=w;
                //     }
                //     else {
                //         external+=w;
                //     }
                // }
                if ((vInX && uInX) || (!vInX && !uInX)) {
                    // If they're in the same set, moving v would add this edge to the cut
                    delta += w;
                } else {
                    // If they're in different sets, moving v would remove this edge from the cut
                    delta -= w;
                }
            }
            
            // ll delta=external-internal;
            if(delta>bestDelta){
                // improved=true;
                bestDelta=delta;
                bestDeltavertex=v;
                movefromX=vInX;
            }

        }

        if(bestDelta>0){
        // if(improved){
            improved=true;
            if(movefromX){
                X.erase(bestDeltavertex);
                Y.insert(bestDeltavertex);
            }
            else{
                Y.erase(bestDeltavertex);
                X.insert(bestDeltavertex);
            }
        }
    }
    return {X,Y,iteration};
}
#endif