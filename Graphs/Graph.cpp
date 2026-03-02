#include<bits/stdc++.h>
using namespace std;

template <typename T>
class graph {
private:
    unordered_map < T, list<T>> adjList;

public:
    void addEdge(T u, T v, bool directed) {
        adjList[u].push_back(v);

        if (!directed) {
            adjList[v].push_back(u);
        }
    }

    void printGraphList() {
        for (auto i : adjList) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }

    void createAdjMat(int u, int v, bool directed) {
        // Create an adjacency matrix
    }
};

int main() {
    int n = 0;
    cout << "Enter the number of nodes:\n";
    cin >> n;
    int m = 0;
    cout << "Enter the number of edges:\n";
    cin >> m;

    graph<int> g;
    cout << "Enter graph relations\n";
    for (int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        // Creating an undirected graph
        g.addEdge(u, v, false);
    }

    g.printGraphList();
}