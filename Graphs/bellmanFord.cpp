#include<bits/stdc++.h>
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n+1, 1e8);
    dist[src] = 0;

    // relax edges n times
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    // detect negative cycle
    // for(int j = 0; j < m; j++){
    //     int u = edges[j][0];
    //     int v = edges[j][1];
    //     int wt = edges[j][2];

    //     if(dist[u] + wt < dist[v]){
    //         return vector<int>(n+1, 1e8);
    //     }
    // }

    return dist;
}