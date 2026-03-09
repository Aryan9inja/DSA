#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>>& vec, int vertices, int edges, int source) {

    unordered_map<int, list<pair<int,int>>> adj;

    for(int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist(vertices, INT_MAX);

    // min heap -> {distance, node}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty()) {

        auto top = pq.top();
        pq.pop();

        int nodeDist = top.first;
        int node = top.second;

        // ignore outdated entries
        if(nodeDist > dist[node]) continue;

        for(auto neighbour : adj[node]) {

            int adjNode = neighbour.first;
            int weight = neighbour.second;

            if(nodeDist + weight < dist[adjNode]) {

                dist[adjNode] = nodeDist + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}