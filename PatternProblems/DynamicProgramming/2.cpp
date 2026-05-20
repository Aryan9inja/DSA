// LC 198 - House Robber
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int rob = nums[i] + solve(nums, i + 2, dp);
        int skip = solve(nums, i + 1, dp);

        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size(), -1);
        // return solve(nums, 0, dp);

        // vector<int> dp(nums.size() + 2, 0);
        int next1 = 0;
        int next2 = 0;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int rob = nums[i] + next2;
            int skip = next1;

            int curr = max(rob, skip);
            next2 = next1;
            next1 = curr;
        }

        return next1;
    }
};