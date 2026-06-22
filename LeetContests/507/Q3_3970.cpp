#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({ edge[1], edge[2] });
        }

        using CurrState = tuple<int, int, int>;
        priority_queue<CurrState, vector<CurrState>, greater<CurrState>> pq;

        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        dist[0][1] = 0;
        pq.push({ 0, 0, 1 });

        while (!pq.empty()) {
            auto [distance, node, streak] = pq.top();
            pq.pop();

            if (node == n - 1) {
                return distance;
            }

            if (distance > dist[node][streak])
                continue;

            for (const auto& [neighbour, weight] : adj[node]) {
                int newStreak =
                    (labels[node] == labels[neighbour]) ? streak + 1 : 1;
                if (newStreak <= k &&
                    distance + weight < dist[neighbour][newStreak]) {
                    dist[neighbour][newStreak] = distance + weight;
                    pq.push({ dist[neighbour][newStreak], neighbour, newStreak });
                }
            }
        }
        return -1;
    }
};