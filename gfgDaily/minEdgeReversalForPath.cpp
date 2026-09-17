#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEdgeReversal(vector<vector<int>>& edges, int n, int src, int dst) {
        vector<vector<pair<int, int>> > adj(n + 1);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back({ v, 0 });
            adj[v].push_back({ u, 1 });
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[src] = 0;
        deque<int> dq;
        dq.push_front(src);

        while (!dq.empty()) {
            int node = dq.front();
            dq.pop_front();

            for (auto& [next, cost] : adj[node]) {
                if (dist[node] + cost < dist[next]) {
                    dist[next] = dist[node] + cost;

                    if (cost == 0) {
                        dq.push_front(next);
                    }
                    else {
                        dq.push_back(next);
                    }
                }
            }
        }

        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};
