#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTime(vector<int>& duration, vector<vector<int>>& dependencies) {

        int n = duration.size();

        // Build the dependency graph.
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto& edge : dependencies) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        // Store the earliest completion time for every module.
        vector<int> finishTime(duration.begin(), duration.end());

        queue<int> q;

        // Start with all modules having no dependencies.
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        int visited = 0;
        int res = 0;

        // Perform topological traversal.
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            visited++;
            res = max(res, finishTime[node]);

            // Update completion time of dependent modules.
            for (int next : adj[node]) {

                finishTime[next] = max(finishTime[next], finishTime[node] + duration[next]);

                if (--indegree[next] == 0)
                    q.push(next);
            }
        }

        // Cycle detected.
        if (visited != n)
            return -1;

        return res;
    }

};
