#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkCycle(int node, vector<bool>& visited, vector<bool>& dfsVisited,
                    vector<vector<int>>& adjList) {
        visited[node] = true;
        dfsVisited[node] = true;

        for(auto &neighbour : adjList[node]){
            if(!visited[neighbour]){
                bool cycle = checkCycle(neighbour, visited, dfsVisited, adjList);
                if(cycle) return true;
            }
            else if(dfsVisited[neighbour]){
                return true;
            }
        }

        dfsVisited[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (const auto& pre : prerequisites) {
            int u = pre[1];
            int v = pre[0];

            adjList[u].push_back(v);
        }

        vector<bool> visited(numCourses);
        vector<bool> dfsVisited(numCourses);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                bool cycle = checkCycle(i, visited, dfsVisited, adjList);
                if(cycle) return false;
            }
        }
        return true;
    }
};