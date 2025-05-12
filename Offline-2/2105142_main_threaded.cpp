#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <mutex>
#include <filesystem>
#include <vector>
#include <string>
#include "Graph.cpp"
#include "Randomized.cpp"
#include "Greedy.cpp"
#include "SemiGreedy.cpp"
#include "LocalSearch.cpp"
#include "GRASP.cpp"

using namespace std;
using namespace chrono;
namespace fs = std::filesystem;

mutex csv_mutex;
ofstream csvFile("2105142.csv");

void runAlgorithmsOnGraph(const string& filepath) {
    ifstream inFile(filepath);
    if (!inFile.is_open()) {
        cerr << "Failed to open: " << filepath << endl;
        return;
    }

    int n, m;
    inFile >> n >> m;
    Graph g(n, m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        inFile >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    inFile.close();

    double alpha = 0.5;
    // int iteration = 100;

    double rand1 = randomizedMaxCut(g, 100);
    auto greedy = greedyMaxCut(g);
    long long greedyW = g.getCutWeight(greedy.first, greedy.second);

    auto semi = semiGreedyMaxCut(g, alpha);
    long long semiW = g.getCutWeight(semi.first, semi.second);

    auto local = localSearchMaxCut(g, semi.first, semi.second);
    long long localW = g.getCutWeight(get<0>(local), get<1>(local));

    auto grasp = graspMaxCut(g, 50, alpha);
    long long graspW = g.getCutWeight(get<0>(grasp), get<1>(grasp));
    
    string name = fs::path(filepath).stem().string(); 
    
    lock_guard<mutex> lock(csv_mutex);
    csvFile << name << "," << n << "," << m << ","
    << rand1 << "," << greedyW << "," << semiW << ","
    << get<2>(local) << "," << localW << ","
    << get<2>(grasp) << "," << graspW << ","
    << "?" << "\n";
    
    cout << "Completed: " << filepath << endl;

}

int main() {
    vector<thread> workers;
    cout << "Process Started. Results will be written to 2105142.csv\n";
    int max_threads = thread::hardware_concurrency();
    vector<string> files;

    for (const auto& entry : fs::directory_iterator("graph_GRASP/set1")) {
        if (entry.path().extension() == ".rud") {
            files.push_back(entry.path().string());
        }
    }

    csvFile << "Name,|V|,|E|,Randomized,Greedy,SemiGreedy,LocalIteration,LocalSearch,GRASPIteration,GRASP,BestKnown\n";

    size_t index = 0;
    while (index < files.size()) {
        while (workers.size() < max_threads && index < files.size()) {
            workers.emplace_back(runAlgorithmsOnGraph, files[index++]);
            // cout<<"ADDED"<<endl;
        }

        for (auto& t : workers) t.join();
        workers.clear();
    }

    csvFile.close();
    cout << "All graphs processed. Results written to 2105142.csv\n";
    return 0;
}
