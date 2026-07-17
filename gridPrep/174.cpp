#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;

    int solve(vector<vector<int>>& dungeon, vector<vector<int>>& dp, int i,
        int j) {
        if (i >= m || j >= n) {
            return INT_MAX;
        }

        if (i == m - 1 && j == n - 1) {
            return max(1, 1 - dungeon[i][j]);
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int need =
            min(solve(dungeon, dp, i + 1, j), solve(dungeon, dp, i, j + 1));

        return dp[i][j] = max(1, need - dungeon[i][j]);
    }

    /*
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(dungeon, dp, 0, 0);
    }
    */

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                int need = min(dp[i + 1][j], dp[i][j + 1]);

                dp[i][j] = max(1, need - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};