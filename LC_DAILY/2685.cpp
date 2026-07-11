#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int completeCount = 0;
        vector<bool> visited(n + 1, false);

        for (int vertex = 0; vertex < n; vertex++) {
            if (visited[vertex])
                continue;

            // arr[0] = vertices count, arr[1] = total edges count
            int componentInfo[2] = { 0, 0 };
            dfs(vertex, graph, visited, componentInfo);

            // Check if component is complete -
            // edges should be vertices * (vertices-1)
            if (componentInfo[0] * (componentInfo[0] - 1) == componentInfo[1]) {
                completeCount++;
            }
        }
        return completeCount;
    }

private:
    void dfs(int curr, vector<vector<int>>& graph, vector<bool>& visited,
        int componentInfo[2]) {
        visited[curr] = true;
        componentInfo[0]++;                     // Increment vertex count
        componentInfo[1] += graph[curr].size(); // Add edges from current vertex

        for (int next : graph[curr]) {
            if (!visited[next]) {
                dfs(next, graph, visited, componentInfo);
            }
        }
    }
};