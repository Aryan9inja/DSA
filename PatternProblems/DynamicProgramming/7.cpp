#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;

    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if (dp[i] != -1)
            return dp[i];
        int maxi = 1;

        for (int j = i + 1; j < n; j++) {
            if (nums[j] > nums[i]) {
                maxi = max(maxi, 1 + solve(nums, j, dp));
            }
        }

        return dp[i] = maxi;
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        // vector<int> dp(n, -1);
        // int ans = 0;
        // for (int i = 0; i < n; i++) {
        //     ans = max(ans, solve(nums, i, dp));
        // }
        // return ans;

        vector<int> dp(n, 1);
        int maxLIS = 1;

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxLIS = max(maxLIS, dp[i]);
        }

        return maxLIS;
    }
};