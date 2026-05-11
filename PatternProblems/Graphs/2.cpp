// LC 200 - Number of Islands
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dirI[4] = {-1, 0, 1, 0};
    int dirJ[4] = {0, -1, 0, 1};

    int m;
    int n;

    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if(grid[i][j] == '0') return;

        grid[i][j] = '0';

        for(int k=0; k<4; k++){
            dfs(i+dirI[k], j+dirJ[k], grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        m = grid.size();
        n = grid[0].size();
        // vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};