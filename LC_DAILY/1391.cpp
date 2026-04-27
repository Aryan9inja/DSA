#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dirs = {
            {},     // dummy (0 unused)
            {3, 1}, // 1 → left ↔ right
            {0, 2}, // 2 → up ↕ down
            {3, 2}, // 3 → left ↔ down
            {1, 2}, // 4 → right ↔ down
            {3, 0}, // 5 → left ↔ up
            {1, 0}  // 6 → right ↔ up
        };

        vector<pair<int, int>> move = {
            {-1, 0}, // up
            {0, 1},  // right
            {1, 0},  // down
            {0, -1}  // left
        };

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({ 0, 0 });
        vis[0][0] = true;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i == m - 1 && j == n - 1)
                return true;

            for (int d : dirs[grid[i][j]]) {
                int ni = i + move[d].first;
                int nj = j + move[d].second;

                if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                    continue;
                if (vis[ni][nj])
                    continue;

                // check if next cell connects back
                int opp = (d + 2) % 4;
                for (int nd : dirs[grid[ni][nj]]) {
                    if (nd == opp) {
                        vis[ni][nj] = true;
                        q.push({ ni, nj });
                    }
                }
            }
        }
        return false;
    }
};