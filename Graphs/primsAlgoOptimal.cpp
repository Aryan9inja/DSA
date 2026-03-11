#include <bits/stdc++.h> 
using namespace std;

typedef pair<int, int> pii; // {weight, node}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // 1. Adjacency List: {neighbor, weight}
    vector<vector<pii>> adjList(n + 1);
    for(int i = 0; i < m; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    // 2. Data structures
    vector<int> key(n + 1, INT_MAX);
    vector<bool> inMST(n + 1, false);
    vector<int> parent(n + 1, -1);
    
    // Min-heap to store {weight, node}
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Start from node 1
    key[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()){
        // 3. Extract the node with the minimum key value
        int u = pq.top().second;
        pq.pop();

        // If the node is already in MST, skip it
        if(inMST[u]) continue;
        
        inMST[u] = true;

        // 4. Explore neighbors
        for(auto it : adjList[u]){
            int v = it.first;
            int weight = it.second;

            if(!inMST[v] && weight < key[v]){
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // 5. Construct result
    vector<pair<pair<int, int>, int>> result;
    for(int i = 2; i <= n; i++){
        if(parent[i] != -1) {
            result.push_back({{parent[i], i}, key[i]});
        }
    }    

    return result;
}