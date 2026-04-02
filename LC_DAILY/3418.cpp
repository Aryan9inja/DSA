#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(vector<vector<int>>& coins, int m, int n, int i, int j,
              int neutralize) {
        if (i == m - 1 && j == n - 1) {
            if (neutralize > 0 && coins[i][j] < 0)
                return 0; // skip this negative coin
            return coins[i][j];
        }

        int down = INT_MIN;
        int right = INT_MIN;
        // At each cell, branch into two choices:
        // 1. Take the coin normally
        // 2. If negative AND neutralize > 0, skip it (spend a neutralize)
        // Then return the max of both branches
        if (i + 1 < m) {
            down = coins[i][j] + solve(coins, m, n, i + 1, j, neutralize);
            if (neutralize > 0 && coins[i][j] < 0)
                down = max(down, solve(coins, m, n, i + 1, j,
                                       neutralize - 1)); // skip this coin
        }
        if (j + 1 < n) {
            right = coins[i][j] + solve(coins, m, n, i, j + 1, neutralize);
            if (neutralize > 0 && coins[i][j] < 0)
                right =
                    max(right, solve(coins, m, n, i, j + 1, neutralize - 1));
        }

        return max(down, right);
    }

    int memoization(vector<vector<int>>& coins, int m, int n, int i, int j,
                    int neutralize, vector<vector<vector<int>>>& dp) {
        if (i == m - 1 && j == n - 1) {
            if (neutralize > 0 && coins[i][j] < 0)
                return 0; // skip this negative coin
            return coins[i][j];
        }

        if (dp[i][j][neutralize] != INT_MIN)
            return dp[i][j][neutralize];

        int down = INT_MIN;
        int right = INT_MIN;
        if (i + 1 < m) {
            down = coins[i][j] +
                   memoization(coins, m, n, i + 1, j, neutralize, dp);
            if (neutralize > 0 && coins[i][j] < 0)
                down = max(down, memoization(coins, m, n, i + 1, j,
                                             neutralize - 1, dp));
        }
        if (j + 1 < n) {
            right = coins[i][j] +
                    memoization(coins, m, n, i, j + 1, neutralize, dp);
            if (neutralize > 0 && coins[i][j] < 0)
                right = max(right, memoization(coins, m, n, i, j + 1,
                                               neutralize - 1, dp));
        }

        return dp[i][j][neutralize] = max(down, right);
    }

    int tabulation(vector<vector<int>>& coins, int m, int n) {
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, INT_MIN / 2)));

        // Base case: bottom-right cell
        for (int k = 0; k <= 2; k++) {
            dp[m - 1][n - 1][k] =
                (k > 0 && coins[m - 1][n - 1] < 0) ? 0 : coins[m - 1][n - 1];
        }

        // Last row: only move is right
        for (int j = n - 2; j >= 0; j--) {
            for (int k = 0; k <= 2; k++) {
                int take = coins[m - 1][j] + dp[m - 1][j + 1][k];
                int skip = (k > 0 && coins[m - 1][j] < 0)
                               ? dp[m - 1][j + 1][k - 1]
                               : INT_MIN / 2;
                dp[m - 1][j][k] = max(take, skip);
            }
        }

        // Last col: only move is down
        for (int i = m - 2; i >= 0; i--) {
            for (int k = 0; k <= 2; k++) {
                int take = coins[i][n - 1] + dp[i + 1][n - 1][k];
                int skip = (k > 0 && coins[i][n - 1] < 0)
                               ? dp[i + 1][n - 1][k - 1]
                               : INT_MIN / 2;
                dp[i][n - 1][k] = max(take, skip);
            }
        }

        // Fill rest bottom-right to top-left
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                for (int k = 0; k <= 2; k++) {
                    // Take this coin normally
                    int down = coins[i][j] + dp[i + 1][j][k];
                    int right = coins[i][j] + dp[i][j + 1][k];

                    // Skip this coin (spend a neutralize)
                    if (k > 0 && coins[i][j] < 0) {
                        down = max(down, dp[i + 1][j][k - 1]);
                        right = max(right, dp[i][j + 1][k - 1]);
                    }

                    dp[i][j][k] = max(down, right);
                }
            }
        }

        return dp[0][0][2];
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        // return solve(coins, m, n, 0, 0, 2);
        // vector<vector<vector<int>>> dp(
        //     m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        // return memoization(coins, m, n, 0, 0, 2, dp);

        return tabulation(coins, m, n);
    }
};