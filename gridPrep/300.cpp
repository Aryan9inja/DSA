#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n);
        dp[0] = 1;
        int ans = 1;

        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            int best = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    best = max(best, dp[j]);
                }
            }
            dp[i] = 1 + best;
            ans = max(ans, dp[i]);
        }

        return ans;
    }
    */

    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int& curr : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), curr);

            if (it == tails.end()) {
                tails.push_back(curr);
            }
            else {
                *it = curr;
            }
        }

        return tails.size();
    }
};