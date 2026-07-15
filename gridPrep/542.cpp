#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] == 0) {
                    q.push({ r, c });
                }
                else {
                    mat[r][c] = 1e9;
                }
            }
        }

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto& d : dir) {
                int newRow = row + d.first;
                int newCol = col + d.second;

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                    mat[newRow][newCol] > mat[row][col] + 1) {
                    mat[newRow][newCol] = mat[row][col] + 1;
                    q.push({ newRow, newCol });
                }
            }
        }

        return mat;
    }
};