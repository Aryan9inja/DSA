// LC 743 - Network Delay Time
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n + 1);
        for (const auto& t : times) {
            int u = t[0];
            int v = t[1];
            int w = t[2];

            adjList[u].push_back({v, w});
        }

        vector<int> time(n + 1, INT_MAX);

        // time, node
        priority_queue<
            pair<int, int>, 
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        time[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            int nodeTime = top.first;
            int node = top.second;

            if (nodeTime > time[node])
                continue;

            for (auto& n : adjList[node]) {
                int adjNode = n.first;
                int adjTime = n.second;

                if (nodeTime + adjTime < time[adjNode]) {
                    time[adjNode] = nodeTime + adjTime;
                    pq.push({time[adjNode], adjNode});
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (time[i] == INT_MAX)
                return -1;
            ans = max(ans, time[i]);
        }

        return ans;
    }
};