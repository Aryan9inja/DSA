#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS traversal starting from a vertex
    void dfsFromVertex(int v, vector<bool>& visited, vector<vector<int>>& adj) {

        // Mark vertex visited
        visited[v] = true;
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfsFromVertex(neighbor, visited, adj);
            }
        }
    }

    // Function to find a mother vertex
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // Adjacency list
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<bool> visited(V, false);
        int candidate = 0;

        // Step 1: Find last finished vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsFromVertex(i, visited, adj);

                // Candidate mother vertex
                candidate = i;
            }
        }

        // Step 2: Check if candidate reaches all vertices
        fill(visited.begin(), visited.end(), false);
        dfsFromVertex(candidate, visited, adj);
        for (bool v : visited)
            if (!v)
                return -1;

        return candidate;
    }
};
