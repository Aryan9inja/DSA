#include<bits/stdc++.h>
using namespace std;

// O(n*maxDeadline)
class Greedy {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }

    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        int n = deadline.size();
        int maxDeadline = 0;
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({ profit[i], deadline[i] });
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        sort(jobs.begin(), jobs.end(), cmp);

        vector<bool> schedule(maxDeadline + 1, false);
        int cnt = 0;
        int maxProfit = 0;
        for (auto job : jobs) {
            int currProfit = job.first;
            int currDeadline = job.second;

            for (int i = currDeadline; i > 0; i--) {
                if (!schedule[i]) {
                    cnt++;
                    maxProfit += currProfit;
                    schedule[i] = true;
                    break;
                }
            }
        }
        return { cnt, maxProfit };
    }
};

// O(n*log(n))
class DisjointSetUnion {
public:
    struct DSU {
        vector<int> parent;
        DSU(int n) {
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++) parent[i] = i;
        }

        // Find the latest available slot
        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]); // Path compression
        }

        // Link slot i to slot i-1
        void unite(int curr, int prev) {
            parent[curr] = prev;
        }
    };

    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first; // Sort by profit descending
    }

    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        int n = deadline.size();
        int maxD = 0;
        vector<pair<int, int>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({ profit[i], deadline[i] });
            maxD = max(maxD, deadline[i]);
        }

        sort(jobs.begin(), jobs.end(), cmp);

        DSU dsu(maxD);
        int cnt = 0;
        int totalProfit = 0;

        for (auto& job : jobs) {
            int p = job.first;
            int d = job.second;

            // Find the maximum available slot <= deadline
            int availableSlot = dsu.find(d);

            // If availableSlot > 0, we can schedule this job
            if (availableSlot > 0) {
                cnt++;
                totalProfit += p;
                // Mark this slot as used by linking it to the previous slot
                dsu.unite(availableSlot, availableSlot - 1);
            }
        }

        return { cnt, totalProfit };
    }
};