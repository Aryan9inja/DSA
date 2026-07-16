#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>> pq;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        static int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

        pq.push({ grid[0][0], 0, 0 });

        while (!pq.empty()) {
            auto [t, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == n - 1) {
                return t;
            }

            if (visited[r][c]) continue;
            visited[r][c] = true;

            for (auto& d : dir) {
                int nR = r + d[0];
                int nC = c + d[1];

                if (nR >= 0 && nR < n && nC >= 0 && nC < n && !visited[nR][nC]) {
                    int nT = max(t, grid[nR][nC]);
                    pq.push({ nT, nR, nC });
                }
            }
        }
        return -1;
    }
};