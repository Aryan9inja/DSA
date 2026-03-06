#include<bits/stdc++.h>
using namespace std;

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    // 1. Corrected definition: vector of lists
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first - 1; 
        int v = edges[i].second - 1;
        adj[u].push_back(v);
        // Calculate indegree while building the graph for efficiency
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        cnt++;

        for (auto neighbour : adj[front]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    // If we visited all nodes, there is NO cycle.
    // If cnt < n, there is a cycle.
    return (cnt != n); 
}