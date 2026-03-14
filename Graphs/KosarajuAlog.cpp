// This algorithm is used to find strongly connected components in a graph
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, stack<int> &st, vector<bool> &visited){
	visited[node]=true;

	for(auto nbr:adj[node]){
		if(!visited[nbr]){
			dfs(nbr, adj, st, visited);
		}
	}

	// topo logic
	st.push(node);
}

void revDfs(int node, vector<bool> &visited, vector<vector<int>> &transpose){
	visited[node]=true;

	for(auto nbr:transpose[node]){
		if(!visited[nbr]){
			revDfs(nbr, visited, transpose);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	vector<vector<int>> adj(v);
	for(int i=0;i<edges.size();i++){
		int u=edges[i][0];
		int v=edges[i][1];

		adj[u].push_back(v);
	}

	// topo sort
	stack<int> st;
	vector<bool> visited(v,false);

	for(int i=0;i<v;i++){
		if(!visited[i]){
			dfs(i, adj, st, visited);
		}
	}

	// create transpose graph
	vector<vector<int>> transpose(v);
	for(int i=0;i<v;i++){
		visited[i]=false;
		for(auto nbr:adj[i]){
			transpose[nbr].push_back(i);
		}
	}

	int count=0;
	while(!st.empty()){
		int top=st.top();
		st.pop();
		if(!visited[top]){
			count++;
			revDfs(top, visited, transpose);
		}
	}

	return count;
}