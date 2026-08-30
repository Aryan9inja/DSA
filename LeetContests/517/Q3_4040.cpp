#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int INF = 1e9;
    int memo[101][5001];
    vector<vector<pair<int, int>>> transitions;

    int solve(int idx, int remSum) {
        if (remSum == 0) return 0;
        if (idx >= transitions.size() || remSum < 0) return INF;

        if (memo[idx][remSum] != -1) {
            return memo[idx][remSum];
        }

        int res = solve(idx + 1, remSum);

        for (const auto& [v, c] : transitions[idx]) {
            if (remSum >= v) {
                int next = solve(idx + 1, remSum - v);
                if (next != INF) {
                    res = min(res, c + next);
                }
            }
        }

        return memo[idx][remSum] = res;
    }

public:
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        transitions.assign(n, {});
        memset(memo, -1, sizeof(memo));

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> bestCost;
            int x = nums[i];

            int val = x;
            int cost = 0;
            while (val <= sum) {
                if (bestCost.find(val) == bestCost.end() || cost < bestCost[val]) {
                    bestCost[val] = cost;
                }
                val *= 2;
                cost++;
            }

            val = x / 2;
            cost = 1;
            while (val > 0) {
                if (bestCost.find(val) == bestCost.end() || cost < bestCost[val]) {
                    bestCost[val] = cost;
                }
                val /= 2;
                cost++;
            }

            for (const auto& [v, c] : bestCost) {
                transitions[i].push_back({ v,c });
            }
        }

        int ans = solve(0, sum);
        return (ans >= INF) ? -1 : ans;
    }
};