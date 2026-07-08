#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCoordinates(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> reachP(n, vector<bool>(m, false));
        vector<vector<bool>> reachQ(n, vector<bool>(m, false));

        queue<pair<int, int>> q;

        auto bfs = [&](queue<pair<int, int>> q, vector<vector<bool>>& visited) {
            int dx[] = { -1, 1, 0, 0 };
            int dy[] = { 0, 0, -1, 1 };

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    if (visited[nx][ny])
                        continue;

                    // Reverse traversal
                    if (mat[nx][ny] < mat[x][y])
                        continue;

                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
            };

        // Station P (Top row + Left column)
        while (!q.empty())
            q.pop();

        for (int j = 0; j < m; j++) {
            if (!reachP[0][j]) {
                reachP[0][j] = true;
                q.push({ 0, j });
            }
        }

        for (int i = 0; i < n; i++) {
            if (!reachP[i][0]) {
                reachP[i][0] = true;
                q.push({ i, 0 });
            }
        }

        bfs(q, reachP);

        // Station Q (Bottom row + Right column)
        while (!q.empty())
            q.pop();

        for (int j = 0; j < m; j++) {
            if (!reachQ[n - 1][j]) {
                reachQ[n - 1][j] = true;
                q.push({ n - 1, j });
            }
        }

        for (int i = 0; i < n; i++) {
            if (!reachQ[i][m - 1]) {
                reachQ[i][m - 1] = true;
                q.push({ i, m - 1 });
            }
        }

        bfs(q, reachQ);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (reachP[i][j] && reachQ[i][j])
                    ans++;
            }
        }

        return ans;
    }
};
