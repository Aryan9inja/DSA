#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        set<pair<int, int>> obstacleSet;
        int x = 0, y = 0, dir = 0, maxDist = 0;

        for (const auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }

        for (int command : commands) {
            if (command == -2) {
                dir = (dir + 3) % 4; // Turn left
            } else if (command == -1) {
                dir = (dir + 1) % 4; // Turn right
            } else {
                // Move forward step by step
                for (int i = 1; i <= command; i++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    // Stop if next position is an obstacle
                    if (obstacleSet.find({nx, ny}) != obstacleSet.end()) {
                        break;
                    }
                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }
        return maxDist;
    }
};