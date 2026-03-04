#include <bits/stdc++.h> 
using namespace std;

void topoSort(int node, vector<bool> &visited,
stack<int> &s, vector<vector<int>> &adj){
    visited[node]=true;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour, visited, s, adj);
        }
    }

    // Put in stack for reverse ordering
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v,false);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i, visited, s, adj);
        }
    }

    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}