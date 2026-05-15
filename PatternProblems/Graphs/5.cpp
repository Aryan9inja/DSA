// LC 210 - Course Schedule II
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);

        for (const auto& pre : prerequisites) {
            int v = pre[0];
            int u = pre[1];

            adjList[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        ans.reserve(numCourses);
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto& n : adjList[node]) {
                if (--indegree[n] == 0)
                    q.push(n);
            }
        }

        if (ans.size() < numCourses) {
            return {};
        }

        return ans;
    }
};