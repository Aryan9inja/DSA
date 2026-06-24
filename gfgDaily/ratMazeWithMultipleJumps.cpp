#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i, int j, vector<vector<int>>& mat,
        vector<vector<int>>& ans, vector<vector<int>>& dp) {
        int n = mat.size();

        if (i >= n || j >= n)
            return false;

        if (i == n - 1 && j == n - 1) {
            ans[i][j] = 1;
            return true;
        }

        if (mat[i][j] == 0)
            return false;

        if (dp[i][j] != -1)
            return dp[i][j];

        ans[i][j] = 1;

        int jump = mat[i][j];

        for (int step = 1; step <= jump; step++) {
            if (solve(i, j + step, mat, ans, dp)) {
                return dp[i][j] = 1;
            }

            if (solve(i + step, j, mat, ans, dp)) {
                return dp[i][j] = 1;
            }
        }

        // Backtrack
        ans[i][j] = 0;
        return dp[i][j] = 0;
    }

    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {

        int n = mat.size();
        if (n == 1)
            return { {1} };

        vector<vector<int>> ans(n, vector<int>(n, 0));

        if (mat[0][0] == 0)
            return { {-1} };

        vector<vector<int>> dp(n, vector<int>(n, -1));

        if (!solve(0, 0, mat, ans, dp))
            return { {-1} };

        return ans;
    }
};
