#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    long long sum = bfs(grid, i, j);

                    if (sum % k == 0)
                        cnt++;
                }
            }
        }

        return cnt;
    }

private:
    int m;
    int n;

    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };

    long long bfs(vector<vector<int>>& grid, int start_i, int start_j) {
        queue<pair<int, int>> q;
        q.push({ start_i, start_j });

        long long sum = grid[start_i][start_j];
        grid[start_i][start_j] = 0;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];

                if (ni < 0 || ni >= m || nj < 0 || nj >= n ||
                    grid[ni][nj] == 0) {
                    continue;
                }

                sum += grid[ni][nj];
                q.push({ ni, nj });
                grid[ni][nj] = 0;
            }
        }

        return sum;
    }
};