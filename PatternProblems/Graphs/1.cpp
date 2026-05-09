// LC 1971 - Find if Path Exists in Graph
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& adjList, int src, int dest, vector<char>& visited) {
        visited[src] = 1;

        if (src == dest)
            return true;

        for (int x : adjList[src]) {
            if (!visited[x]) {
                if (dfs(adjList, x, dest, visited))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;

        vector<vector<int>> adjList(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<char> visited(n, 0);
        return dfs(adjList, source, destination, visited);
    }
};