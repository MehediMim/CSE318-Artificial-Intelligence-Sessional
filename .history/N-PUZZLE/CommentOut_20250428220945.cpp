// States* AStar::Solve(){

//     pq.push(startState);

//     while(!pq.empty()){
//     // for(int i=0;i<1000;i++){

//         // cout<<i<<endl;
//         // printPQ();

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


// States* AStar::Solve() {
//     // Use a set of serialized grids to speed up visited checking
//     unordered_set<string> visited_set;

//     auto serialize = [](const vector<vector<int>>& grid) -> string {
//         stringstream ss;
//         for (auto& row : grid)
//             for (auto& val : row)
//                 ss << val << ",";
//         return ss.str();
//     };

//     pq.push(startState);
//     visited_set.insert(serialize(startState->getGrid()));

//     while (!pq.empty()) {
//         States* current = pq.top();
//         pq.pop();

//         stateExpanded++;

//         if (isGoal(current)) {
//             return current;
//         }

//         vector<States*> neighbours = generateNeighbours(current);

//         for (auto state : neighbours) {
//             string key = serialize(state->getGrid());
//             if (visited_set.find(key) == visited_set.end()) {
//                 state->setMove(current->getMove() + 1);
//                 pq.push(state);
//                 visited_set.insert(key); // Insert into visited
//                 stateExplored++;
//             }
//         }
//     }

//     return nullptr;
// }