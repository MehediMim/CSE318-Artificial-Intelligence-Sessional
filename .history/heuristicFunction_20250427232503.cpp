#ifndef HEURISTICFUNCTION_H
#define HEURISTICFUNCTION_H


#include <bits/stdc++.h>
using namespace std;


double HammingDistance(vector<vector<int>> grid, int k)
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

double ManhattanDistance(vector<vector<int>> grid, int k)
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

#endif
