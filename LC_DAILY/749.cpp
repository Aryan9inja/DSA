#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m, n;
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };

    struct Region {
        vector<pair<int, int>> cells;
        set<pair<int, int>> frontier;
        int walls = 0;
    };

    bool isSafe(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x,
        int y, Region& region) {

        visited[x][y] = true;
        region.cells.push_back({ x, y });

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!isSafe(nx, ny))
                continue;

            if (grid[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(grid, visited, nx, ny, region);
            }
            else if (grid[nx][ny] == 0) {
                // Each adjacent uninfected cell boundary requires a wall
                region.walls++;
                region.frontier.insert({ nx, ny });
            }
        }
    }

public:
    int containVirus(vector<vector<int>>& isInfected) {
        m = isInfected.size();
        n = isInfected[0].size();
        int total_walls = 0;

        while (true) {
            vector<vector<bool>> visited(m, vector<bool>(n, false));

            vector<Region> regions;

            // Step 1: Identify all independent infected regions
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (isInfected[i][j] == 1 && !visited[i][j]) {
                        Region region;

                        dfs(isInfected, visited, i, j, region);

                        if (!region.frontier.empty()) {
                            regions.push_back(region);
                        }
                    }
                }
            }

            // Stop condition: No active virus region can spread anywhere
            if (regions.empty())
                break;

            // Step 2: Pick the region that threatens the most uninfected cells
            int target_idx = 0;
            for (int i = 1; i < regions.size(); i++) {
                if (regions[i].frontier.size() >
                    regions[target_idx].frontier.size())
                    target_idx = i;
            }

            // Step 3: Contain the chosen region with walls (mark as 2)
            total_walls += regions[target_idx].walls;
            for (auto& [x, y] : regions[target_idx].cells) {
                isInfected[x][y] = 2; // 2 -> contained cell
            }

            // Step 4: Spread all remaining uncontained regions into their
            // frontiers
            for (int i = 0; i < regions.size(); i++) {
                if (i == target_idx)
                    continue;

                for (auto& [fx, fy] : regions[i].frontier) {
                    isInfected[fx][fy] = 1;
                }
            }
        }

        return total_walls;
    }
};