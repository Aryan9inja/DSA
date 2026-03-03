#include<bits/stdc++.h>
using namespace std;

bool isCycicBFS(int src, unordered_map<int,bool> &visited,
unordered_map<int,list<int>> &adj){
    unordered_map<int,int> parent;
    parent[src]=-1;
    visited[src]=1;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front=q.front();
        q.pop();

        for(auto neighbour : adj[front]){
            if(visited[neighbour] && neighbour!=parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=true;
                parent[neighbour]=front;
            }
        }
    }
    return false;
}

bool isCycicDFS(int node, int parent, unordered_map<int,bool> &visited,
unordered_map<int,list<int>> &adj){
    visited[node]=1;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool isCycleDetected=isCycicDFS(neighbour, node, visited, adj);
            if(isCycleDetected) return true;
        }
        else if(parent!=neighbour){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Create adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Handle disconnected components
    unordered_map<int,bool> visited;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            // bool ans=isCycicBFS(i, visited, adj);
            bool ans=isCycicDFS(i, -1, visited, adj);
            if(ans) return "Yes";
        }
    }
    return "No";
}
