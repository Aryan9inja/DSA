#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid,
        vector<vector<bool>>& vis) {
        vis[x][y] = true;

        int dirs[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

        for (auto& d : dirs) {
            int nx = x + d[0];
            int ny = y + d[1];

            // FIX 1: Check ny against grid[0].size(), not grid.size()
            if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) {
                continue;
            }

            if (grid[nx][ny] != grid[x][y]) continue;

            if (!vis[nx][ny]) {
                if (dfs(nx, ny, x, y, grid, vis)) return true;
            }
            else if (nx != px || ny != py) {
                return true;
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // FIX 2: A cycle requires at least a 2x2 area, so m >= 2 and n >= 2
        if (m < 2 || n < 2) return false;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};