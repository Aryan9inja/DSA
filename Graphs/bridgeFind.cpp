#include<bits/stdc++.h>
using namespace std;

void dfs(int &node, int &parent, int &timer, vector<int> &disc, vector<int> &low,
    vector<bool> &vis, vector<vector<int>> &adj, vector<vector<int>> &res){
    vis[node]=true;
    disc[node]=low[node]=timer++;

    for(auto nbr: adj[node]){
        if(nbr==parent) continue;

        else if(!vis[nbr]){
            dfs(nbr, node, timer, disc, low, vis, adj, res);
            low[node]=min(low[node],low[nbr]);

            if(low[nbr]>disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                res.push_back(ans);
            }
        }

        else{
            // Back Edge
            low[node]=min(low[node],disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    vector<vector<int>> adjList(v);
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer=0;
    vector<int> discoveryTime(v,-1);
    vector<int> lowestDiscoveryTime(v,-1);
    int parent=-1;
    vector<bool> visited(v,false);

    vector<vector<int>> result;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i, parent, timer, discoveryTime,
            lowestDiscoveryTime, visited, adjList, result);
        }
    }
    return result;
}