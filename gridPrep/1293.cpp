#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        static int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

        int m = grid.size();
        int n = grid[0].size();

        if (k >= m + n - 2)
            return m + n - 2;

        // row, col, steps, remaining k
        queue<tuple<int, int, int, int>> q;
        q.push({ 0, 0, 0, k });

        // -1 = visited
        // maximum remaining eliminations when reaching this cell
        vector<vector<int>> vis(m, vector<int>(n, -1));
        vis[0][0] = k;

        while (!q.empty()) {
            auto [row, col, steps, rem_k] = q.front();
            q.pop();

            if (row == m - 1 && col == n - 1)
                return steps;

            for (auto& d : dir) {
                int newRow = row + d[0];
                int newCol = col + d[1];

                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n) {
                    continue;
                }

                // if (grid[newRow][newCol] == 0 && vis[newRow][newCol] < rem_k) {
                //     vis[newRow][newCol] = rem_k;
                //     q.push({newRow, newCol, steps + 1, rem_k});
                // } else if (grid[newRow][newCol] == 1) {
                //     // Destroy or skip
                //     if (rem_k-1 > vis[newRow][newCol] && rem_k != 0) {
                //         vis[newRow][newCol] = rem_k-1;
                //         q.push({newRow, newCol, steps + 1, rem_k - 1});
                //     }
                // }

                int next_k = rem_k - grid[newRow][newCol];

                if (next_k >= 0 && vis[newRow][newCol] < next_k) {
                    vis[newRow][newCol] = next_k;
                    q.push({ newRow, newCol, steps + 1, next_k });
                }
            }
        }

        return -1;
    }
};