#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursive(int start, int end) {
        if (start >= end)
            return 0;

        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans = min(ans,
                      i + max(recursive(start, i - 1), recursive(i + 1, end)));
        }
        return ans;
    }

    int memoization(int start, int end, vector<vector<int>>& dp) {
        if (start >= end)
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans = min(ans, i + max(memoization(start, i - 1, dp),
                                   memoization(i + 1, end, dp)));
        }
        return dp[start][end] = ans;
    }

    int tabulation(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));

        for (int start = n; start >= 1; start--) {
            for (int end = start; end <= n; end++) {
                if (start == end)
                    continue;

                else {
                    int ans = INT_MAX;
                    for (int i = start; i <= end; i++) {
                        ans =
                            min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
                    }
                    dp[start][end]= ans;
                }
            }
        }
        return dp[1][n];
    }

public:
    int getMoneyAmount(int n) {
        // return recursive(1, n);

        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return memoization(1, n, dp);

        return tabulation(n);
    }
};