#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dirI[4] = { -1, 0, 1, 0 };
    int dirJ[4] = { 0, -1, 0, 1 };

    int n;
    int m;

    void dfs(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 0;

        for (int k = 0; k < 4; k++) {
            int newI = i + dirI[k];
            int newJ = j + dirJ[k];
            if (newI >= 0 && newI < n && newJ >= 0 && newJ < m) {
                if (grid[newI][newJ] == 1) {
                    dfs(grid, newI, newJ);
                }
            }
        }
    }

public:
    int cntOnes(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1)
                dfs(grid, i, 0);
            if (grid[i][m - 1] == 1)
                dfs(grid, i, m - 1);
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1)
                dfs(grid, 0, j);
            if (grid[n - 1][j] == 1)
                dfs(grid, n - 1, j);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};
