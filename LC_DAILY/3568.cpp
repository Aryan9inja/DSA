#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m;
    int n;

    struct State {
        int x;
        int y;
        int energy;
        int mask;
    };

    bool isSafe(int x, int y, vector<string>& grid) {
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 'X') {
            return false;
        }

        return true;
    }

public:
    int minMoves(vector<string>& classroom, int energy) {
        m = classroom.size();
        n = classroom[0].size();

        vector<vector<int>> litterId(m, vector<int>(n, -1));
        int startX = -1;
        int startY = -1;
        int k = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                }
                else if (classroom[i][j] == 'L') {
                    litterId[i][j] = k;
                    k++;
                }
            }
        }

        int fullMask = (1 << k) - 1;

        // best[i][j][mask] -
        // largest energy to reach i, j with currMask
        vector<vector<vector<int>>> best(
            m, vector<vector<int>>(n, vector<int>(1 << k, -1)));

        queue<State> q;
        q.push({ startX, startY, energy, 0 });
        best[startX][startY][0] = energy;

        int dx[4] = { -1, 0, 1, 0 };
        int dy[4] = { 0, -1, 0, 1 };

        int moves = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                State curr = q.front();
                q.pop();

                if (curr.mask == fullMask) {
                    return moves;
                }

                if (curr.energy == 0) {
                    continue;
                }

                for (int d = 0; d < 4; d++) {
                    int nx = curr.x + dx[d];
                    int ny = curr.y + dy[d];

                    if (!isSafe(nx, ny, classroom)) {
                        continue;
                    }

                    int newEnergy = curr.energy - 1;
                    int mask = curr.mask;

                    if (classroom[nx][ny] == 'L') {
                        mask |= (1 << litterId[nx][ny]);
                    }

                    if (classroom[nx][ny] == 'R') {
                        newEnergy = energy;
                    }

                    if (newEnergy > best[nx][ny][mask]) {
                        best[nx][ny][mask] = newEnergy;

                        q.push({ nx, ny, newEnergy, mask });
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};