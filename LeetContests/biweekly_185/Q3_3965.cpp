#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int node, const vector<vector<int>>& adj, const vector<int>& baseTime) {
        if (adj[node].empty()) {
            return baseTime[node];
        }

        long long mini = 1e18;
        long long maxi = -1e18;

        for (int child : adj[node]) {
            long long childFinish = solve(child, adj, baseTime);
            mini = min(mini, childFinish);
            maxi = max(maxi, childFinish);
        }

        long long ownDuration = (maxi - mini) + baseTime[node];
        return maxi + ownDuration;
    }

    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adjList(n);
        for (const auto& e : edges) {
            adjList[e[0]].push_back(e[1]);
        }

        return solve(0, adjList, baseTime);
    }
};