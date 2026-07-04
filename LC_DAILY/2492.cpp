#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int dist = road[2];

            adj[u].push_back({ v, dist });
            adj[v].push_back({ u, dist });
        }

        int mini = INT_MAX;
        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (const auto& neighbour : adj[curr]) {
                int nextNode = neighbour.first;
                int nextDist = neighbour.second;

                mini = min(mini, nextDist);

                if (!visited[nextNode]) {
                    visited[nextNode] = true;
                    q.push(nextNode);
                }
            }
        }

        return mini;
    }
};