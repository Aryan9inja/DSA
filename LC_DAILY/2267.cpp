#include<bits/stdc++.h>
using namespace std;

#include <vector>

using namespace std;

class Solution {
public:
    int m, n;

    int dp[101][101][205];

    bool solve(vector<vector<char>>& grid, int i, int j, int bal) {
        if (bal < 0) return false;

        if (bal > (m - 1 - i) + (n - 1 - j)) return false;

        if (i == m - 1 && j == n - 1) {
            return bal == 0;
        }

        if (dp[i][j][bal] != -1) {
            return dp[i][j][bal];
        }

        bool canReach = false;

        if (i + 1 < m) {
            int nextBal = bal + (grid[i + 1][j] == '(' ? 1 : -1);
            canReach = canReach || solve(grid, i + 1, j, nextBal);
        }

        if (!canReach && j + 1 < n) {
            int nextBal = bal + (grid[i][j + 1] == '(' ? 1 : -1);
            canReach = canReach || solve(grid, i, j + 1, nextBal);
        }

        return dp[i][j][bal] = canReach;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        if ((m + n - 1) % 2 != 0) {
            return false;
        }

        memset(dp, -1, sizeof(dp));

        return solve(grid, 0, 0, 1);
    }
};