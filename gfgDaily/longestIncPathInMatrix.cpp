#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longIncPath(vector<vector<int>>& matrix, int n, int m) {
        vector<pair<int, int>> dir = { { 0, 1 },{ 1, 0 },{ 0, -1 },{ -1, 0 } };
        vector<vector<int>> degree(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (auto d : dir) {
                    int x = i + d.first;
                    int y = j + d.second;

                    if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] < matrix[i][j]) {
                        degree[i][j]++;
                    }
                }
            }
        }

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (degree[i][j] == 0) {
                    q.push({ i, j });
                }
            }
        }

        int pathLength = 0;

        while (!q.empty()) {
            pathLength++;

            int levelSize = q.size();

            for (int k = 0; k < levelSize; k++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (auto d : dir) {
                    int x = i + d.first;
                    int y = j + d.second;

                    if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] > matrix[i][j]) {
                        degree[x][y]--;
                        if (degree[x][y] == 0) {
                            q.push({ x, y });
                        }
                    }
                }
            }
        }

        return pathLength;
    }
};
