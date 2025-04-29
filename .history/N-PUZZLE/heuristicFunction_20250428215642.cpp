#ifndef HEURISTICFUNCTION_H
#define HEURISTICFUNCTION_H


#include <bits/stdc++.h>
using namespace std;


double HammingDistance(vector<vector<int>> grid)
{
    int k= grid.size();
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

double ManhattanDistance(vector<vector<int>> grid)
{
    int k= grid.size();
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

double EuclideanDistance(vector<vector<int>> grid)
{
    int k= grid.size();
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

double LinearConflict(vector<vector<int>> grid)
{
    int k= grid.size();
    double Manhattan = ManhattanDistance(grid);
    int linearConflict = 0;
    for (int row = 0; row < k; row++) {
        for (int col1 = 0; col1 < k - 1; col1++) {
            for (int col2 = col1 + 1; col2 < k; col2++) {
                int tile1 = grid[row][col1];
                int tile2 = grid[row][col2];

                if (tile1 != 0 && tile2 != 0) {
                    int goalRow1 = (tile1 - 1) / k;
                    int goalCol1 = (tile1 - 1) % k;
                    int goalRow2 = (tile2 - 1) / k;
                    int goalCol2 = (tile2 - 1) % k;

                    if (goalRow1 == row && goalRow2 == row) {
                        if (goalCol1 > goalCol2) {
                            linearConflict++;
                        }
                    }
                }
            }
        }
    }

    for (int col = 0; col < k; col++) {
        for (int row1 = 0; row1 < k - 1; row1++) {
            for (int row2 = row1 + 1; row2 < k; row2++) {
                int tile1 = grid[row1][col];
                int tile2 = grid[row2][col];

                if (tile1 != 0 && tile2 != 0) {
                    int goalRow1 = (tile1 - 1) / k;
                    int goalCol1 = (tile1 - 1) % k;
                    int goalRow2 = (tile2 - 1) / k;
                    int goalCol2 = (tile2 - 1) % k;

                    if (goalCol1 == col && goalCol2 == col) {
                        if (goalRow1 > goalRow2) {
                            linearConflict++;
                        }
                    }
                }
            }
        }
    }
    return Manhattan + 2 * linearConflict;
}
#endif
