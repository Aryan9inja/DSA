#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;

    // Movement vectors for navigating up, down, left, and right
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    // Maps out the closest Manhattan distance to any thief for every cell
    vector<vector<int>> distToThief;

    // PHASE 1: Multi-Source BFS to build the proximity map in O(n^2)
    void precompute(vector<vector<int>>& grid) {
        distToThief.assign(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Seed the queue with ALL thieves simultaneously to expand outward evenly
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    distToThief[r][c] = 0;
                    q.push({ r, c });
                }
            }
        }

        // Standard BFS layer-by-layer expansion
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // If neighbor is within bounds and hasn't been visited yet
                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    distToThief[nr][nc] == -1) {
                    distToThief[nr][nc] = distToThief[r][c] + 1;
                    q.push({ nr, nc });
                }
            }
        }
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        // Edge Case: Instant fail if the start or end cell has a thief
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }

        // Run Phase 1 to compute individual cell safeness scores
        precompute(grid);

        // PHASE 2: Modified Dijkstra using a Max-Heap to track the safest path
        // Priority Queue format: { path_safeness_bottleneck, { r, c } }
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        // Tracks the maximum bottleneck score found to reach any given cell
        vector<vector<int>> maxSafenessToCell(n, vector<int>(n, -1));

        // Initialize Dijkstra from the starting cell (0, 0)
        maxHeap.push({ distToThief[0][0], {0, 0} });
        maxSafenessToCell[0][0] = distToThief[0][0];

        while (!maxHeap.empty()) {
            auto [currSafeness, cell] = maxHeap.top();
            auto [r, c] = cell;
            maxHeap.pop();

            // The first time the destination pops off the max-heap, it's guaranteed to be the optimal path
            if (r == n - 1 && c == n - 1) {
                return currSafeness;
            }

            // Optimization: If we've already found a strictly better path to this cell, skip stale processing
            if (currSafeness < maxSafenessToCell[r][c]) {
                continue;
            }

            // Explore 4-directional neighbors
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    // BOTTLENECK RULE: A path is only as safe as its single closest step to a thief.
                    // If the neighbor is closer to a thief than our current path's history, our score drops.
                    int newSafeness = min(currSafeness, distToThief[nr][nc]);

                    // MAXIMIZATION RULE: Among competing paths to this neighbor, we want the SAFEST one.
                    // If this path preserves a larger distance from thieves than previous attempts, update it.
                    if (newSafeness > maxSafenessToCell[nr][nc]) {
                        maxSafenessToCell[nr][nc] = newSafeness;
                        maxHeap.push({ newSafeness, {nr, nc} });
                    }
                }
            }
        }

        return 0;
    }
};