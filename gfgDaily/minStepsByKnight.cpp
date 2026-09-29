#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStepToReachTarget(vector<int>& knightPos,
        vector<int>& targetPos, int n) {
        int x = knightPos[0] - 1;
        int y = knightPos[1] - 1;
        int tx = targetPos[0] - 1;
        int ty = targetPos[1] - 1;

        int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
        int dy[] = { 1, -1, 1, -1, 2, -2, 2, -2 };

        queue<pair<pair<int, int>, int>> q;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push({ { x, y }, 0 });
        visited[x][y] = true;

        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;

            q.pop();

            if (x == tx && y == ty)
                return steps;

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({ { nx, ny }, steps + 1 });
                }
            }
        }

        return -1;
    }
};
