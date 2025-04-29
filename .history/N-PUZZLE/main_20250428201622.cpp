#include <bits/stdc++.h>
#include "States.cpp"
#include "AStar.cpp"
#include "heuristicFunction.cpp"

using namespace std;



int main()
{
    int k=3;
    States* st=new States(k);
    int temp;
    vector<vector<int>> v;
    v.resize(k, vector<int>(k, 0));
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            cin>>temp;
            v[i][j]=temp;
        }
    }
    st->setGrid(v);

    AStar* astar=new AStar(st,EuclideanDistance);
    astar->solvePath();

}