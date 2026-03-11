#include <bits/stdc++.h> 
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>>& g) {
    // Create adj list
    vector<vector<pair<int, int>>> adjList(n + 1);
    for (int i = 0;i < m;i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adjList[u].push_back({ v,w });
        adjList[v].push_back({ u,w });
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    key[1] = 0;

    for (int i = 1;i < n;i++) {
        int mini = INT_MAX;
        int u;

        // find min node
        for (int v = 1;v <= n;v++) {
            if (mst[v] == false && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }

        // mark min node as true
        mst[u] = true;

        // check adjacent node
        for (auto it : adjList[u]) {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2;i <= n;i++) {
        result.push_back({ {parent[i],i},key[i] });
    }

    return result;
}
