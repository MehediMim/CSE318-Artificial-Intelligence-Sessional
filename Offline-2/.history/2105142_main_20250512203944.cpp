#include <iostream>
#include <fstream>
#include <chrono>
#include "Graph.cpp"
#include "Randomized.cpp"
#include "Greedy.cpp"
#include "SemiGreedy.cpp"
#include "LocalSearch.cpp"
#include "GRASP.cpp"

using namespace std;
using namespace chrono;

void printSet(const unordered_set<int>& S, const string& name) {
    cout << name << ": { ";
    for (int v : S) cout << v << " ";
    cout << "}\n";
}

int main() {
    ifstream inFile("graph_GRASP/set1/g32.rud");
    if (!inFile.is_open()) {
        cerr << "Error: Cannot open input.txt\n";
        return 1;
    }

    int n, m;
    inFile >> n >> m;
    double alpha=0.5;
    int iteration=10;
    
    Graph g(n, m);
    for (int i = 0; i < m; ++i) {
         int u, v, w;
         inFile >> u >> v >> w;
         g.addEdge(u, v, w);
     //     cout<<n<<m<<endl;
     }
     inFile.close();

    cout << "\n====== MAX-CUT ALGORITHMS COMPARISON ======\n";

    // Randomized
    auto t1 = high_resolution_clock::now();
    double avgCut = randomizedMaxCut(g, iteration);
    auto t2 = high_resolution_clock::now();
    cout << "[1] Randomized Max-Cut: " << avgCut 
         << " (Time: " << duration_cast<milliseconds>(t2 - t1).count() << " ms)\n";

    // Greedy
    t1 = high_resolution_clock::now();
    auto greedy = greedyMaxCut(g);
    auto greedyW = g.getCutWeight(greedy.first, greedy.second);
    t2 = high_resolution_clock::now();
    cout << "[2] Greedy Max-Cut: " << greedyW 
         << " (Time: " << duration_cast<milliseconds>(t2 - t1).count() << " ms)\n";

    // Semi-Greedy
    t1 = high_resolution_clock::now();
    auto semi = semiGreedyMaxCut(g, alpha);
    auto semiW = g.getCutWeight(semi.first, semi.second);
    t2 = high_resolution_clock::now();
    cout << "[3] Semi-Greedy Max-Cut: " << semiW 
         << " (Time: " << duration_cast<milliseconds>(t2 - t1).count() << " ms)\n";

    // Local Search
    t1 = high_resolution_clock::now();
    auto local = localSearchMaxCut(g, semi.first, semi.second);
    auto localW = g.getCutWeight(get<0>(local),get<1>(local));
    t2 = high_resolution_clock::now();
    cout << "[4] Local Search: " << localW 
         << " (Time: " << duration_cast<milliseconds>(t2 - t1).count() << " ms)\n";

    // GRASP
    t1 = high_resolution_clock::now();
    auto grasp = graspMaxCut(g, iteration, alpha);
    auto graspW = g.getCutWeight(get<0>(grasp),get<1>(grasp));
    t2 = high_resolution_clock::now();
    cout << "[5] GRASP (50 iters, alpha=0.5): " << graspW 
         << " (Time: " << duration_cast<milliseconds>(t2 - t1).count() << " ms)\n";

    cout << "\n====== END OF REPORT ======\n";
    return 0;
}
