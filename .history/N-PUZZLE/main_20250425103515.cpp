#include <bits/stdc++.h>
using namespace std;

int HammingDistance(vector<vector<int>>*grid,int k){
    int distance=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if((*grid)[i][j]!=0 and (*grid)[i][j]!=(i+1)*k+(j+1)){
                distance++;
            }
        }
    }
    return distance; 
}

int HammingDistance(vector<vector<int>>*grid,vector<vector<int>>*goal,int k){
    int distance=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if((*grid)[i][j]!=0 and (*grid)[i][j]!=(*goal)[i][j]){
                distance++;
            }
        }
    }
    return distance; 
}
 
int main()
{

}