#include <bits/stdc++.h>
#include "States.cpp"
using namespace std;

int HammingDistance(vector<vector<int>> grid, int k)
{
    int distance = 0;
    for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){
            if (grid[i][j] != 0 and grid[i][j] != (i) * (k) + (j + 1)){
                distance++;
            }
        }
    }
    return distance;
}

int ManhattanDistance(vector<vector<int>> grid, int k)
{
    int distance = 0;
    for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){

            if (grid[i][j] != 0){
                int var = grid[i][j];
                int row = (var-1) / k;
                int col = (var-1) % k ;
                    distance+=(abs(i-row)+abs(j-col));
            }
        }
    }
    return distance;
}

double EuclideanDistance(vector<vector<int>> grid, int k)
{
    double distance = 0.0;
    for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){

            if (grid[i][j] != 0){
                int var = grid[i][j];
                int row = (var-1) / k;
                int col = (var-1) % k ;
                    distance+=sqrt(pow((i-row),2)+pow((j-col),2));
            }
        }
    }
    return distance;
}

int main()
{
    States* st=new States(3);
    // int temp;
    vector<vector<int>> v;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            // cin>>temp;
            cin>>v[i][j];
        }
    }
    st->setGrid(v);
    cout<<HammingDistance(v,3)<<endl;
    cout<<ManhattanDistance(v,3)<<endl;
    cout<<EuclideanDistance(v,3)<<endl;


}