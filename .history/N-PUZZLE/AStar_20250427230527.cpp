#ifndef ASTAR_H
#define ASTAR_H

#include <bits/stdc++.h>
#include "States.cpp"
using namespace std;

struct comparator
{
    bool operator()(States *const &s1, States *const &s2)
    {
        
    }
};

class AStar
{
    private:
        priority_queue<States*, vector<States*>, comparator> pq;

    public : 

    AStar();
    ~AStar();
};

AStar::AStar(/* args */)
{
}

AStar::~AStar()
{
}

#endif