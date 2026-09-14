#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n, m;

    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, -1, 0, 1 };

    bool isSafe(vector<vector<int>>& mat, int i, int j) {
        if (mat[i][j] != 1) {
            return false;
        }

        for (int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj] == 0) {
                return false;
            }
        }

        return true;
    }

public:
    int shortestPath(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        // i, j, dist
        queue<tuple<int, int, int>> q;

        for (int i = 0; i < n; i++) {
            if (isSafe(mat, i, 0)) {
                q.push({ i, 0, 1 });
                mat[i][0] = -1;
            }
        }

        while (!q.empty()) {
            auto [i, j, dist] = q.front();
            q.pop();

            if (j == m - 1)
                return dist;

            for (int k = 0; k < 4; k++) {
                int ni = i + dr[k];
                int nj = j + dc[k];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && isSafe(mat, ni, nj)) {
                    q.push({ ni, nj, dist + 1 });

                    mat[ni][nj] = -1;
                }
            }
        }

        return -1;
    }
};
