#include<bits/stdc++.h>
using namespace std;

static const long long MINI = -1e16;
static const long long DP_STATE = -2e18;

class Solution {
    long long solve(int i, int state, int op, vector<int>& nums, int k,
        vector<vector<long long>>& dp) {
        if (i < 0)
            return MINI;

        if (dp[i][state] != DP_STATE)
            return dp[i][state];

        long long v = nums[i];
        long long operation = (op == 0) ? (long long)v * k : v / k;
        long long ans = MINI;

        if (state == 0) {
            ans = max(v, solve(i - 1, 0, op, nums, k, dp) + v);
        }
        else if (state == 1) {
            long long prev1 = solve(i - 1, 0, op, nums, k, dp);
            long long prev2 = solve(i - 1, 1, op, nums, k, dp);
            ans = max({ operation, prev1 + operation, prev2 + operation });
        }
        else if (state == 2) {
            long long prev1 = solve(i - 1, 1, op, nums, k, dp);
            long long prev2 = solve(i - 1, 2, op, nums, k, dp);
            if (prev1 != MINI)
                ans = max(ans, prev1 + v);
            if (prev2 != MINI)
                ans = max(ans, prev2 + v);
        }

        return dp[i][state] = ans;
    }

public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxi = MINI;

        // op => 0 for mul, 1 for div
        for (int op = 0; op <= 1; op++) {
            vector<vector<long long>> dp(n, vector<long long>(3, DP_STATE));

            for (int i = 0; i < n; i++) {
                maxi = max({ maxi, solve(i, 1, op, nums, k, dp),
                            solve(i, 2, op, nums, k, dp) });
            }
        }

        return maxi;
    }
};