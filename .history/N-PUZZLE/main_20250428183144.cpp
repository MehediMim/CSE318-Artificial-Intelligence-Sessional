#include <bits/stdc++.h>
#include "States.cpp"
#include "AStar.cpp"
#include "heuristicFunction.cpp"

using namespace std;



int main()
{
    States* st=new States(4);
    int temp;
    vector<vector<int>> v;
    v.resize(4, vector<int>(4, 0));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>temp;
            v[i][j]=temp;
        }
    }
    st->setGrid(v);

    AStar* astar=new AStar(st,HammingDistance);
    astar->solvePath();

}