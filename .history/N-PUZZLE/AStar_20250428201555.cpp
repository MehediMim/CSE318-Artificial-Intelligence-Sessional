// #ifndef ASTAR_H
// #define ASTAR_H

// #include <bits/stdc++.h>
// #include "States.cpp"
// #include "heuristicFunction.cpp"
// using namespace std;

// class AStar
// {
// private:
//     function<double(vector<vector<int>>)> hFN;

//     struct comparator
//     {
//         AStar* astar;
//         comparator(AStar*  astar):astar(astar){}
//         bool operator()(States *const &s1, States *const &s2)
//         {
//             ////////////////////////////////////////////////////
//             double h1=astar->hFN(s1->getGrid());
//             double h2=astar->hFN(s2->getGrid());

//             int g1=s1->getMove();
//             int g2=s2->getMove();

//             double f1=h1+g1;
//             double f2=h2+g2;
//             return f1>f2;
//         }
//     };

//     priority_queue<States *, vector<States *>, comparator> pq{comparator(this)};
//     vector<vector<vector<int>>>visited;
//     States* startState;
//     States* goalState;
    
//     bool isSolvable(States* startState);
//     bool isGoal(States *state);
//     vector<States*> generateNeighbours(States* current);
//     States* Solve();

//     int move=0;
//     int stateExplored=0;
//     int stateExpanded=0;

//     void printGrid(vector<vector<int>> grid);
//     bool isVisited(vector<vector<int>> grid);
//     void printPQ() ;
    
    
    
// public:
//     AStar(States *startState,function<double(vector<vector<int>>)> hFN){
//         this->hFN=hFN;
//         this->startState=startState;
//     };

//     void solvePath();
// };


// bool AStar::isGoal(States *state){
//     vector<vector<int>> v= state->getGrid();
//     int k=v.size();
//     // cout<<"______________________"<<endl;
//     // cout<<k<<endl;
//     for(int i=0;i<k;i++){
//         for(int j=0;j<k;j++){
//             int goal;
//             if(k-i==1 and k-j==1){
//                 goal=0;
//             }
//             else goal=k*i+(j+1);
//             // cout<<goal<<" ";
//             if(v[i][j]!=goal)return 0;
//         }
//         // cout<<endl;
//     }
//     return 1;
// }

// States* AStar::Solve(){

//     pq.push(startState);

//     while(!pq.empty()){
//     // for(int i=0;i<1000;i++){

//         // cout<<i<<endl;
//         printPQ();

//         // cout<<pq.size()<<endl;
//         States* current = pq.top();
//         pq.pop();
//         stateExpanded++;
//         if(isGoal(current)){
//             return current;
//         }

//         // current->setVisited();
//         visited.push_back(current->getGrid());
        
//         vector <States*>neighbours=generateNeighbours(current);
//         // stateExpanded++;
        
//         for(auto state : neighbours){
//             // if(!state->getVisited()){
//             if(!isVisited(state->getGrid())){
//                 pq.push(state);
//                 stateExplored++;
//                 state->setMove(current->getMove()+1);
//                 // visited.push_back(state->getGrid());
//             }
//         }
        
//     }
//     return  nullptr;
// };

// vector<States*> AStar::generateNeighbours(States* current){
//     int z_x=-1;
//     int z_y=-1;
//     vector<vector<int>> currGrid = current->getGrid();
//     int k=currGrid.size();
//     vector<States*>statePacket;
    
//     for(int i=0;i<k;i++){
//         for(int j=0;j<k;j++){
//             if(currGrid[i][j]==0){
//                 z_x=i;
//                 z_y=j;
//                 break;
//             }
//         }
//         if(z_x!=-1)break;
//     }
    
//     vector<pair<int,int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
    
//     for(auto d:dir){
//         if(z_x+d.first>=0 and z_x+d.first<k){
//             if(z_y+d.second>=0 and z_y+d.second<k){
//                 vector<vector<int>>newGrid=currGrid;
//                 swap(newGrid[z_x][z_y],newGrid[z_x+d.first][z_y+d.second]);
//                 // newGrid[z_x+d.first][z_y+d.second]=0;
//                 States* newState=new States(k);
//                 newState->setGrid(newGrid);
//                 newState->setParent(current);
//                 statePacket.push_back(newState);
//             }
//         }
//     }
//     return statePacket;
// }

// bool AStar::isSolvable(States* startState){
//     vector<int>flat;
//     // cout<<"Line130"<<endl;
//     int k=startState->getGrid().size();
//     for(int i=0;i<k;i++){
//         for(int j=0;j<k;j++){
//             if(startState->getGrid()[i][j]!=0)flat.push_back(startState->getGrid()[i][j]);
//         }
//     }
    
//     // cout<<"Line138"<<endl;
//     int z_x=-1;
//     int z_y=-1;
//     for(int i=0;i<k;i++){
//         for(int j=0;j<k;j++){
//             if(startState->getGrid()[i][j]==0){
//                 z_x=i;
//                 z_y=j;
//                 break;
//             }
//         }
//         if(z_x!=-1)break;
//     }
    
//     // cout<<"Line152"<<endl;
//     int inversion=0;
    
//     for(int i=0;i<flat.size();i++){
//         for(int j=i+1;j<flat.size();j++){
//             if(flat[j]<flat[i])inversion++;
//         }
//     }
//     // cout<<inversion<<endl;
//     // cout<<k<<endl;
//     // cout<<k-z_x<<endl;
//     // cout<<"Line160"<<endl;
//     if(k%2!=0){
//         // cout<<"Line162"<<endl;
//         // cout<<inversion<<endl;
//         if(inversion%2==0){
//             // cout<<inversion<<endl;
//             return 1;
//         }
//     }
//     else{
//         // cout<<"Line168"<<endl;
//         if(inversion%2!=0){
//             if((k-z_x) % 2 ==0) return 1;
//         }
//         // cout<<"Line172"<<endl;
//         if(inversion%2==0){
//             if((k-z_x) % 2 !=0) return 1;
//         }
//     }
//     // cout<<"Line177"<<endl;
//     return 0;

// }

// void AStar::solvePath(){
//     if(!isSolvable(this->startState)){
//         cout<<"Unsolvable puzzle"<<endl;
//         return;
//     }
//     else{
//         // cout<<"Is solvable checking"<<endl;
//         goalState=Solve();
//         // cout<<"Is solvable checked"<<endl;
//     }
    
//     States* temp=goalState;
//     vector<States*>stateBox;
//     while(temp->getParent()!=nullptr){
//         stateBox.push_back(temp);
//         // move++;
//         temp=temp->getParent();
//     }
//     stateBox.push_back(startState);
//     cout<<"Path generated"<<endl;

//     reverse(stateBox.begin(),stateBox.end());
//     cout<<stateBox.size()<<endl;

//     cout<<"Minimum number of moves "<<goalState->getMove()<<endl;
//     cout<<"State Explored "<<stateExplored<<endl;
//     cout<<"State Expanded "<<stateExpanded<<endl;

//     for(States* st: stateBox){
//         cout<<">"<<endl;
//         printGrid(st->getGrid());
//         cout<<endl;
//     }
    
// }

// void AStar::printGrid(vector<vector<int>>grid){
//     int k=grid.size();
//     for(int i=0;i<k;i++){
//         for(int j=0;j<k;j++){
//             cout<<grid[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

// bool AStar::isVisited(vector<vector<int>>grid){
//     int k=grid.size();
//     // bool _visited=false;
//     for(auto gridInVisited : visited){
//         bool vstd=true;
//         for(int i=0;i<k;i++){
//             for(int j=0;j<k;j++){
//                 if(grid[i][j]!=gridInVisited[i][j]){
//                     vstd=false;
//                     break;
//                 }
//             }
//         }
//         if(vstd==true) return true;
//     }
//     return false;
// }

// void AStar::printPQ() {
//     priority_queue<States*, vector<States*>, comparator> temp = pq; // 🛑 Make a copy

//     cout << "Current Priority Queue:" << endl;

//     while (!temp.empty()) {
//         States* element = temp.top();
//         temp.pop();

//         printGrid(element->getGrid()); // your existing printGrid function
//         cout << "----" << endl;
//     }
// }


// #endif

#ifndef ASTAR_H
#define ASTAR_H

#include <bits/stdc++.h>
#include <memory> // For unique_ptr
#include "States.cpp" // Assumed to define States class
#include "heuristicFunction.cpp" // Assumed to define heuristic function

using namespace std;

// Custom hash and equality for vector<vector<int>> to use in unordered_set
struct GridHash {
    size_t operator()(const vector<vector<int>>& grid) const {
        size_t hash = 0;
        for (const auto& row : grid) {
            for (int val : row) {
                hash ^= std::hash<int>{}(val) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
        }
        return hash;
    }
};

struct GridEqual {
    bool operator()(const vector<vector<int>>& a, const vector<vector<int>>& b) const {
        return a == b;
    }
};

class AStar {
private:
    function<double(vector<vector<int>>)> hFN; // Heuristic function
    vector<vector<int>> goalGrid; // Configurable goal state (Fix #9)
    bool debug; // Debug flag for conditional output (Fix #12)
    const int MAX_ITERATIONS = 1000000; // Prevent infinite loops (Fix #4)

    // Comparator for priority queue
    struct comparator {
        AStar* astar;
        comparator(AStar* astar) : astar(astar) {}
        bool operator()(const unique_ptr<States>& s1, const unique_ptr<States>& s2) {
            double h1 = astar->hFN(s1->getGrid());
            double h2 = astar->hFN(s2->getGrid());

            // Debugging check for heuristic (Fix #10)
            if (h1 < 0 || h2 < 0) {
                cerr << "Warning: Negative heuristic value detected!" << endl;
            }

            int g1 = s1->getMove();
            int g2 = s2->getMove();

            double f1 = h1 + g1;
            double f2 = h2 + g2;
            return f1 > f2; // Min-heap based on f = g + h
        }
    };

    // Priority queue with unique_ptr to manage memory (Fix #1)
    priority_queue<unique_ptr<States>, vector<unique_ptr<States>>, comparator> pq;
    
    // Use unordered_set for efficient visited checking (Fix #5)
    unordered_set<vector<vector<int>>, GridHash, GridEqual> visited;
    
    unique_ptr<States> startState; // Use unique_ptr for memory management (Fix #1)
    unique_ptr<States> goalState;  // Store goal state (Fix #7)

    int stateGenerated = 0; // Nodes added to queue (Fix #8)
    int stateExpanded = 0;  // Nodes popped from queue (Fix #8)

    bool isSolvable(const States* startState);
    bool isGoal(const States* state);
    vector<unique_ptr<States>> generateNeighbours(States* current);
    unique_ptr<States> Solve();
    void printGrid(const vector<vector<int>>& grid);
    bool isVisited(const vector<vector<int>>& grid);
    void printPQ();

public:
    // Constructor with configurable goal state and debug flag (Fix #9, #12)
    AStar(unique_ptr<States> startState, function<double(vector<vector<int>>)> hFN,
          const vector<vector<int>>& goalGrid, bool debug = false)
        : hFN(hFN), goalGrid(goalGrid), debug(debug), startState(std::move(startState)),
          pq(comparator(this)) { // Initialize pq after construction (Fix #2)
    }

    void solvePath();
};

bool AStar::isGoal(const States* state) {
    // Compare with configurable goal state (Fix #9)
    return state->getGrid() == goalGrid;
}

unique_ptr<States> AStar::Solve() {
    pq.push(std::move(startState)); // Transfer ownership (Fix #1)
    startState = nullptr; // Prevent accidental use

    int iterations = 0;
    while (!pq.empty() && iterations < MAX_ITERATIONS) { // Iteration limit (Fix #4)
        iterations++;
        if (debug) printPQ(); // Conditional debug output (Fix #12)

        auto current = std::move(pq.top()); // Move ownership (Fix #1)
        pq.pop();
        stateExpanded++; // Correct counting (Fix #8)

        if (isGoal(current.get())) {
            return current; // Goal found
        }

        // Mark as visited before generating neighbors (Fix #3)
        visited.insert(current->getGrid());

        auto neighbours = generateNeighbours(current.get());
        for (auto& state : neighbours) {
            if (!isVisited(state->getGrid())) {
                state->setMove(current->getMove() + 1); // Correct move counting (Fix #6)
                pq.push(std::move(state)); // Transfer ownership (Fix #1)
                stateGenerated++; // Correct counting (Fix #8)
            }
        }
    }

    if (iterations >= MAX_ITERATIONS) {
        cout << "Terminated: Maximum iterations reached" << endl;
    }
    return nullptr; // No solution found
}

vector<unique_ptr<States>> AStar::generateNeighbours(States* current) {
    vector<unique_ptr<States>> statePacket;
    auto currGrid = current->getGrid();
    int k = currGrid.size();
    int z_x = -1, z_y = -1;

    // Find blank tile
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (currGrid[i][j] == 0) {
                z_x = i;
                z_y = j;
                break;
            }
        }
        if (z_x != -1) break;
    }

    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    for (auto d : dir) {
        int new_x = z_x + d.first;
        int new_y = z_y + d.second;
        if (new_x >= 0 && new_x < k && new_y >= 0 && new_y < k) {
            auto newGrid = currGrid;
            swap(newGrid[z_x][z_y], newGrid[new_x][new_y]);
            auto newState = make_unique<States>(k); // Managed memory (Fix #1)
            newState->setGrid(newGrid);
            newState->setParent(current);
            statePacket.push_back(std::move(newState));
        }
    }
    return statePacket;
}

bool AStar::isSolvable(const States* startState) {
    vector<int> flat;
    int k = startState->getGrid().size();
    int z_x = -1, z_y = -1;
    auto grid = startState->getGrid();

    // Compute blank position and flatten grid in one pass (Fix #11)
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (grid[i][j] == 0) {
                z_x = i;
                z_y = j;
            } else {
                flat.push_back(grid[i][j]);
            }
        }
    }

    int inversion = 0;
    for (int i = 0; i < flat.size(); i++) {
        for (int j = i + 1; j < flat.size(); j++) {
            if (flat[j] < flat[i]) inversion++;
        }
    }

    if (k % 2 != 0) {
        return inversion % 2 == 0; // Odd-sized grid: even inversions
    } else {
        // Even-sized grid: inversion parity depends on blank row
        return (inversion % 2 == 0) == ((k - z_x) % 2 != 0);
    }
}

void AStar::solvePath() {
    if (!isSolvable(startState.get())) {
        cout << "Unsolvable puzzle" << endl;
        return;
    }

    goalState = Solve();
    if (!goalState) { // Null check (Fix #7)
        cout << "No solution found" << endl;
        return;
    }

    vector<States*> stateBox;
    States* temp = goalState.get();
    while (temp != nullptr) {
        stateBox.push_back(temp);
        temp = temp->getParent();
    }

    reverse(stateBox.begin(), stateBox.end());
    cout << "Path generated" << endl;
    cout << "Path length: " << stateBox.size() << endl;
    cout << "Minimum number of moves: " << goalState->getMove() << endl; // Correct counting (Fix #6)
    cout << "States Generated: " << stateGenerated << endl; // Standard terminology (Fix #8)
    cout << "States Expanded: " << stateExpanded << endl;

    for (States* st : stateBox) {
        cout << ">" << endl;
        printGrid(st->getGrid());
        cout << endl;
    }
}

void AStar::printGrid(const vector<vector<int>>& grid) {
    int k = grid.size();
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool AStar::isVisited(const vector<vector<int>>& grid) {
    // Efficient lookup using unordered_set (Fix #5)
    return visited.find(grid) != visited.end();
}

void AStar::printPQ() {
    // Copy queue for debugging (Fix #12)
    auto temp = pq;
    cout << "Current Priority Queue:" << endl;
    while (!temp.empty()) {
        auto element = std::move(temp.top());
        temp.pop();
        printGrid(element->getGrid());
        cout << "----" << endl;
    }
}

#endif