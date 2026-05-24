// LC 416 - Partition Equal Subset Sum
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;

public:
    bool solve(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (i >= n || target < 0)
            return false;

        if (dp[i][target] != -1)
            return dp[i][target];

        bool pick = solve(nums, i + 1, target - nums[i], dp);
        bool skip = solve(nums, i + 1, target, dp);

        return dp[i][target] = pick || skip;
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return false;

        int target = sum / 2;

        // vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // return solve(nums, 0, target, dp);

        // vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        vector<bool> dp(target + 1, false);
        // for (int i = 0; i <= n; i++) {
        //     dp[i][0] = true;
        // }
        dp[0] = true;

        for (int i = n - 1; i >= 0; i--) {
            // Iterate backwards to prevent reusing nums[i]
            // We only need to check down to nums[i] because anything
            // smaller than nums[i] can't possibly include it anyway.
            for (int t = target; t >= nums[i]; t--) {
                // dp[t] acts as 'skip', dp[t - nums[i]] acts as 'pick'
                dp[t] = dp[t] || dp[t - nums[i]];
            }
        }

        return dp[target];
    }
};