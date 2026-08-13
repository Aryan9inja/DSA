#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
	vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
		vector<vector<pair<int, int>> > adj(V);
		vector<int> indegree(V, 0);
		
		for (auto& e : edges) {
			int u = e[0];
			int v = e[1];
			int w = e[2];
			
			adj[u].push_back({v, w});
			indegree[v]++;
		}
		
		queue<int> q;
		for (int i = 0; i<V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		
		vector<int> topoSort;
		topoSort.reserve(V);
		
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			
			topoSort.push_back(node);
			
			for (auto& neighbour : adj[node]) {
				int v = neighbour.first;
				
				if (--indegree[v] == 0) {
					q.push(v);
				}
			}
		}
		
		vector<int> dist(V, INT_MIN);
		dist[src] = 0;
		
		for (int node : topoSort) {
			if (dist[node] == INT_MIN) {
				continue;
			}
			
			for (auto& neighbour : adj[node]) {
				int v = neighbour.first;
				int w = neighbour.second;
				
				dist[v] = max(dist[v], dist[node] + w);
			}
		}
		
		return dist;
	}
};
