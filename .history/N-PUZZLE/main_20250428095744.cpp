#include <bits/stdc++.h>
#include "States.cpp"
using namespace std;



int main()
{
    States* st=new States(3);
    int temp;
    vector<vector<int>> v;
    v.resize(3, vector<int>(3, 0));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>temp;
            v[i][j]=temp;
        }
    }
    st->setGrid(v);

    

}