#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_set>
using namespace std;
#define ll long long

struct Edge{
    int u;
    int v;
    int w;
};

class Graph{

private:
    int n;
    int m;
    vector<Edge> edges;
    vector<unordered_set<int>> adj;
    vector<vector<int>> edgeWeight;

    
public:    
    Graph(int n,int m){
        this->n=n;
        this->m=m;
        adj.resize(n + 1);
        edgeWeight.resize(n + 1, vector<int>(n + 1, 0)); 

    }
    void addEdge(int u, int v, int w){
        edges.push_back({u, v, w});
        adj[u].insert(v);
        adj[v].insert(u);
        edgeWeight[u][v] = w;
        edgeWeight[v][u] = w;
    }

    int getVertexCount(){
        return n;
    }
    int getEdgeCount(){
        return m;
    }
    vector<unordered_set<int>> getAdj(){
        return adj;
    }
    // void setAdj(vector<unordered_set<int>> adj){
    //     this->adj=adj;
    // }
    vector<Edge> getEgde(){
        return edges;
    }

    ll getCutWeight(unordered_set<int>X,unordered_set<int>Y){
        ll totalWeight=0;
        for(auto e : edges){
            if(X.count(e.u) and Y.count(e.v)){
                totalWeight+=e.w;
            }
            if(Y.count(e.u) and X.count(e.v)){
                totalWeight+=e.w;
            }
        }
        return totalWeight;
    }

    Edge getMaxWeight(){
        int w=-1;
        Edge ed;
        for(auto e:edges){
            if(e.w>w){
                w=e.w;
                ed=e;
            }
        }
        return ed;
    }
    
    ll sumWeightsBetween(int z, const unordered_set<int>& S) {
        ll total = 0;
        for (int neighbor : adj[z]) {  // You should use `adj` directly, not `g.getAdj()[z]`
            if (S.count(neighbor)) {
                total += edgeWeight[z][neighbor]; // O(1)
            }
        }
        return total;
    }   

    int getValueOfEdge(int u,int v){
        // for(auto e : edges){
        //     if(u==e.u and v==e.v){
        //         return e.w;
        //     }
        //     else if(u==e.v and v==e.u){
        //         return e.w;
        //     }
        // }
        return edgeWeight[u][v];
        // return 0;
    }
};

#endif