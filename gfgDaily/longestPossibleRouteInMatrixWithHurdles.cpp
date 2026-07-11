#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m, n;
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    int dfs(vector<vector<int>>& mat, int i, int j, int x, int y) {
        if (i == x && j == y) {
            return 0;
        }

        if (i < 0 || i >= m || j < 0 || j >= n || mat[i][j] == 0) {
            return -1;
        }

        mat[i][j] = 0;

        int maxLength = -1;

        for (int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];

            int length = dfs(mat, ni, nj, x, y);

            if (length != -1) {
                maxLength = max(maxLength, length + 1);
            }
        }

        mat[i][j] = 1;

        return maxLength;
    }

public:
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        m = mat.size();
        n = mat[0].size();

        if (mat[xs][ys] == 0 || mat[xd][yd] == 0) {
            return -1;
        }

        return dfs(mat, xs, ys, xd, yd);
    }
};
