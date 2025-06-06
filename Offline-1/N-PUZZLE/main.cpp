#include <bits/stdc++.h>
#include "States.cpp"
#include "AStar.cpp"
#include "heuristicFunction.cpp"

using namespace std;



int main()
{
    int k;
    cin>>k;
    States* st=new States(k);
    int temp;
    vector<vector<int>> v;
    v.resize(k, vector<int>(k, -1));
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            cin>>temp;
            v[i][j]=temp;
        }
    }
    st->setGrid(v);

    AStar* astar=new AStar(st,HammingDistance);
    astar->solvePath();

}