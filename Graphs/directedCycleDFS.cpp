#include<bits/stdc++.h>
using namespace std;

bool checkDfsCycle(int node, unordered_map<int,bool> &visited,
unordered_map<int,bool> &dfsVisited, unordered_map<int,list<int>> &adjList){
  visited[node]=true;
  dfsVisited[node]=true;

  for(auto neighbour:adjList[node]){
    if(!visited[neighbour]){
      bool cycleDetected=checkDfsCycle(neighbour,visited,dfsVisited,adjList);
      if(cycleDetected) return true;
    }
    else if(dfsVisited[neighbour]){
      return true;
    }
  }

  dfsVisited[node]=false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>> adjList;
  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;

    adjList[u].push_back(v);
  }

  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsVisited;
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      bool cycleFound=checkDfsCycle(i,visited,dfsVisited,adjList);
      if(cycleFound) return true;
    }
  }
  return false;
}