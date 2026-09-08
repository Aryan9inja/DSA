#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search2D(vector<vector<char>>& grid, int row, int col, string& word) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[row][col] != word[0])
            return false;

        int len = word.size();

        vector<int>x = { -1, -1, -1, 0, 0, 1, 1, 1 };
        vector<int>y = { -1, 0, 1, -1, 1, -1, 0, 1 };

        for (int dir = 0; dir < 8; dir++) {
            int k, currX = row + x[dir], currY = col + y[dir];

            for (k = 1; k < len; k++) {
                if (currX >= m || currX < 0 || currY >= n || currY < 0)
                    break;

                if (grid[currX][currY] != word[k])
                    break;

                currX += x[dir], currY += y[dir];
            }

            if (k == len)
                return true;
        }

        return false;
    }

    vector<vector<int>> searchWord(vector<vector<char>>& mat, string& word) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (search2D(mat, i, j, word)) {
                    ans.push_back({ i, j });
                }
            }
        }

        return ans;
    }
};
