#include <bits/stdc++.h> 
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    // find all indegree
    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j:i){
            indegree[j]++;
        }
    }

    // push 0 indegree nodes
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    // do BFS
    vector<int> ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();

        // ans store
        ans.push_back(front);

        // neighbour indegree update
        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}