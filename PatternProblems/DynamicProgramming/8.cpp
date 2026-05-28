// LC 62 - Unique Paths
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (i >= m || j >= n) {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = solve(i + 1, j, m, n, dp) + solve(i, j + 1, m, n, dp);
    }

    int uniquePaths(int m, int n) {
        // memoization
        /*
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
        */

        // tabulation
        /*
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                    continue;

                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }

        return dp[0][0];
        */

        // Space Optimal
        vector<int> dp(n + 1, 0);
        dp[n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue;

                dp[j] = dp[j] + dp[j + 1];
            }
        }
        return dp[0];
    }
};