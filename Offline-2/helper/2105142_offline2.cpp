// #include <iostream>
// #include <chrono>
// #include "Graph.cpp"
// #include "Randomized.cpp"
// #include "Greedy.cpp"
// #include "SemiGreedy.cpp"
// #include "LocalSearch.cpp"
// #include "GRASP.cpp"

// using namespace std;
// using namespace chrono;

// void printSet(const unordered_set<int> &S, const string &name)
// {
//     cout << name << ": { ";
//     for (int v : S)
//         cout << v << " ";
//     cout << "}\n";
// }

// int main()
// {
//     int n = 1000, m = 1000;
//     Graph g(n, m);

//     random_device rd;
//     mt19937 gen(rd());
//     uniform_int_distribution<> nodeDist(1, n);
//     uniform_int_distribution<> weightDist(1, 20); // weights between 1 and 20

//     unordered_set<string> edgeSet; // to avoid duplicates

//     int added = 0;
//     while (added < m)
//     {
//         int u = nodeDist(gen);
//         int v = nodeDist(gen);
//         if (u == v)
//             continue;

//         // Make sure edge is not already added
//         string key = to_string(min(u, v)) + "-" + to_string(max(u, v));
//         if (edgeSet.count(key))
//             continue;

//         int w = weightDist(gen);
//         g.addEdge(u, v, w);
//         edgeSet.insert(key);
//         ++added;
//     }

//     cout << "\n====== MAX-CUT ALGORITHMS COMPARISON ======\n";

//     // 1. Randomized Max-Cut
//     auto t1 = high_resolution_clock::now();
//     double avgCut = randomizedMaxCut(g, 100);
//     auto t2 = high_resolution_clock::now();
//     auto durationRand = duration_cast<milliseconds>(t2 - t1);
//     cout << "\n[1] Randomized Max-Cut (100 runs): ";
//     cout << avgCut << " (time: " << durationRand.count() << " ms)\n";

//     // 2. Greedy Max-Cut
//     t1 = high_resolution_clock::now();
//     auto greedy = greedyMaxCut(g);
//     unordered_set<int> greedyX = greedy.first;
//     unordered_set<int> greedyY = greedy.second;
//     ll greedyWeight = g.getCutWeight(greedyX, greedyY);
//     t2 = high_resolution_clock::now();
//     auto durationGreedy = duration_cast<milliseconds>(t2 - t1);
//     cout << "\n[2] Greedy Max-Cut:\n";
//     printSet(greedyX, "X");
//     printSet(greedyY, "Y");
//     cout << "Cut Weight: " << greedyWeight << " (time: " << durationGreedy.count() << " ms)\n";

//     // 3. Semi-Greedy Max-Cut
//     t1 = high_resolution_clock::now();
//     auto semi = semiGreedyMaxCut(g, 0.5);
//     unordered_set<int> semiX = semi.first;
//     unordered_set<int> semiY = semi.second;
//     ll semiWeight = g.getCutWeight(semiX, semiY);
//     t2 = high_resolution_clock::now();
//     auto durationSemi = duration_cast<milliseconds>(t2 - t1);
//     cout << "\n[3] Semi-Greedy Max-Cut (alpha=0.5):\n";
//     printSet(semiX, "X");
//     printSet(semiY, "Y");
//     cout << "Cut Weight: " << semiWeight << " (time: " << durationSemi.count() << " ms)\n";

//     // 4. Local Search Max-Cut
//     cout << "Local" << endl;
//     t1 = high_resolution_clock::now();
//     auto local = localSearchMaxCut(g, semiX, semiY);
//     cout << "Local" << endl;
//     unordered_set<int> localX = local.first;
//     unordered_set<int> localY = local.second;
//     ll localWeight = g.getCutWeight(localX, localY);
//     t2 = high_resolution_clock::now();
//     auto durationLocal = duration_cast<milliseconds>(t2 - t1);
//     cout << "\n[4] Local Search after Semi-Greedy:\n";
//     printSet(localX, "X");
//     printSet(localY, "Y");
//     cout << "Cut Weight: " << localWeight << " (time: " << durationLocal.count() << " ms)\n";

//     // 5. GRASP Max-Cut
//     t1 = high_resolution_clock::now();
//     auto grasp = graspMaxCut(g, 50, 0.5);
//     unordered_set<int> graspX = grasp.first;
//     unordered_set<int> graspY = grasp.second;
//     ll graspWeight = g.getCutWeight(graspX, graspY);
//     t2 = high_resolution_clock::now();
//     auto durationGrasp = duration_cast<milliseconds>(t2 - t1);
//     cout << "\n[5] GRASP Max-Cut (50 iterations, alpha=0.5):\n";
//     printSet(graspX, "X");
//     printSet(graspY, "Y");
//     cout << "Cut Weight: " << graspWeight << " (time: " << durationGrasp.count() << " ms)\n";

//     cout << "\n====== END OF COMPARISON ======\n";
//     return 0;
// }


