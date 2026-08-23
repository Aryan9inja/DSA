#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        if (mat[r][c] == '#') {
            return 0;
        }

        vector<vector<int>> minUp(n, vector<int>(m, INT_MAX));

        deque<pair<int, int>> dq;

        minUp[r][c] = 0;
        dq.push_back({ r,c });

        int dr[] = { -1,0,1,0 };
        int dc[] = { 0,1,0,-1 };
        int cost[] = { 1,0,0,0 };

        while (!dq.empty()) {
            auto [currR, currC] = dq.front();
            dq.pop_front();

            int currUp = minUp[currR][currC];

            for (int i = 0; i < 4; i++) {
                int newR = currR + dr[i];
                int newC = currC + dc[i];

                if (newR < 0 || newC < 0 || newR >= n || newC >= m || mat[newR][newC] == '#') {
                    continue;
                }

                int nextUp = currUp + cost[i];

                if (nextUp < minUp[newR][newC]) {
                    minUp[newR][newC] = nextUp;

                    if (cost[i] == 0) {
                        dq.push_front({ newR,newC });
                    }
                    else {
                        dq.push_back({ newR,newC });
                    }
                }
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (minUp[i][j] != INT_MAX) {
                    int usedUp = minUp[i][j];

                    int usedDown = usedUp - (r - i);

                    if (usedUp <= u && usedDown <= d) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};