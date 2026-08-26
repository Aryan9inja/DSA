#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        vector<int> dist(V, 0);

        // Relax all edges V - 1 times.
        for (int i = 0; i < V - 1; i++) {
            bool updated = false;

            for (const auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }

            // No update means distances have stabilized.
            if (!updated) {
                return false;
            }
        }

        // Check whether any edge can still be relaxed.
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] + w < dist[v]) {
                return true;
            }
        }

        return false;
    }
};
