#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	vector<vector<int>> adj(n+1);
	for(int i=0;i<m;i++){
		int u=edges[i].first;
		int v=edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<bool> visited(n+1,false);
	vector<int> parent(n+1,-1);

	queue<int> q;
	q.push(s);
	parent[s]=-1;
	visited[s]=1;

	while(!q.empty()){
		int front=q.front();
		q.pop();

		for(auto neighbour:adj[front]){
			if(!visited[neighbour]){
				visited[neighbour]=1;
				parent[neighbour]=front;
				q.push(neighbour);
			}
		}
	}

	// prepare shortest path
	vector<int> ans;
	int currentNode=t;
	ans.push_back(t);

	while(currentNode!=s){
		currentNode=parent[currentNode];
		ans.push_back(currentNode);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
