#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubseq(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) {
            return 1;
        }

        unordered_map<int, int> dp;
        int ans = 1;

        for (int i = 0; i < n; ++i) {
            if (dp.count(arr[i] + 1) > 0
                || dp.count(arr[i] - 1) > 0) {

                dp[arr[i]] = 1 +
                    max(dp[arr[i] + 1], dp[arr[i] - 1]);
            }
            else {
                dp[arr[i]] = 1;
            }

            ans = max(ans, dp[arr[i]]);
        }

        return ans;
    }
};
